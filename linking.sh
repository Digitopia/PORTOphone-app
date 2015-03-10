# run this from the project root

# uncomment the one to run
# PLATFORM=osx
# PLATFORM=ios
PLATFORM=android

cd PORTOphone_${PLATFORM}/src
ln -sf ../../src/* .
cd ..

mkdir -p bin/data/images/low-res
mkdir -p bin/data/images/high-res
mkdir -p bin/data/sounds

cd bin/data/images/high-res
ln -sf ../../../../../data/images/high-res/* .
cd ..

cd low-res
ln -sf ../../../../../data/images/low-res/* .
cd ..

cd ..

cd sounds
ln -sf ../../../../data/sounds/* .
