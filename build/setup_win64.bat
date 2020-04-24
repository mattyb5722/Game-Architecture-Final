@echo off

mkdir ga7-win64
cd ga7-win64
cmake -G "Visual Studio 15 2017 Win64" ../../src/engine
cd ..
