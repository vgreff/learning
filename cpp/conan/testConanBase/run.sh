
rm -rf build
conan install . --install-folder build --build=missing
conan build . --build-folder build
