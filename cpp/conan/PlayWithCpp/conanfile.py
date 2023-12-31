from conans import ConanFile, CMake


class PlayWithCppAppConan(ConanFile):
    settings = [ "os", "compiler", "build_type", "arch" ]

    requires = [
        "poco/1.9.4",
        "boost/1.80.0"
    ]

    generators = [ "cmake", "gcc", "txt", "virtualenv", "virtualbuildenv", "virtualrunenv" ]

    default_options = {"poco:shared": True, "openssl:shared": True}

    # def imports(self):
    #     self.copy("*.so", dst="bin", src="bin")  # From bin to bin
    #     self.copy("*.so", dst="lib", src="lib")  # From lib to lib
    #     self.copy("*.a*", dst="lib", src="lib")  # From lib to lib


    def build(self):
        cmake = CMake(self, generator="Ninja")
        cmake.configure()
        cmake.build()

 
