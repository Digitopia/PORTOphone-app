# run this from the project root

# ANDROID

cd PORTOphone_android/src
ln -sf ../../src/* .
cd ..

cd bin/data/

cd images
ln -sf ../../../../data/images/* .

cd ..

cd sounds
ln -sf ../../../../data/sounds/* .

cd ../../../../


# OSX

cd PORTOphone_osx/src
ln -sf ../../src/* .
cd ..

cd bin/data/

cd images
ln -sf ../../../../data/images/* .

cd ..

cd sounds
ln -sf ../../../../data/sounds/* .
