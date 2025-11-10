mkdir build
cd build
cmake ..
msbuild /P:Configuration=Release craftgame.vcxproj
start /WAIT /B Release/craftgame.exe
