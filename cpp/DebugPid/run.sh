
rm -rf build
conan install . --install-folder build --update --build=missing
conan build . --build-folder build
