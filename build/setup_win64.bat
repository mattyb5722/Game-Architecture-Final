@echo off

mkdir gaFinal-win64
cd gaFinal-win64
cmake -G "Visual Studio 15 2017 Win64" ../../src/engine
cd ..
