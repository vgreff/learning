from conans import ConanFile, CMake


class PocoTimerConan(ConanFile):
    settings = [ "os", "compiler", "build_type", "arch" ]
    requires = [
        "poco/1.9.4",
        "boost/1.80.0"
    ]
    generators = [ "cmake", "gcc", "txt", "virtualenv", "virtualbuildenv", "virtualrunenv" ]
    default_options = {"poco:shared": True, "openssl:shared": True}

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")  # From bin to bin
        self.copy("*.dylib*", dst="bin", src="lib")  # From lib to bin


    def build(self):
        cmake = CMake(self, generator="Ninja")
        cmake.configure()
        cmake.build()

 
