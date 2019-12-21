This is lab 5 for TCNJ ELC363 with Dr. Hernandez. The code does not synthesize, it is not meant to.
The code does produce valid waveforms with a few known bugs. The B (branch) instruction did not have
to be implemented so it is commented out but believed to work (not tested fully). The CBZ (conditional
branch) does correctly branch to the new location but does not return. The PC (program counter) increments
by 1 instead of 4. This processor is modeled after the LEGv8 arm processor so it uses three .dat files 
which can be opened with notepad. They IM (instruction memory), DM (data memory) and RM (register memory).
We put each of our models in seperate files but they can be combined. The graded report was not returned
but due to final grades, we believe it received a high score.