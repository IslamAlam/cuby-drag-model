
!which gcc

% https://de.mathworks.com/help/releases/R2019b/matlab/matlab_external/change-default-gcc-compiler-on-linux-system.html
copyfile(fullfile(matlabroot,'extern','examples','refbook','timestwo.c'),'.','f')
mex -v GCC='/usr/bin/gcc63' timestwo.c