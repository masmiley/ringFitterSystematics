# ringFitterSystematics
Atmospheric Systematic Propagation for the SNO experiment. Applies High and Low Energy Systematics for D2O phase.

## Use
In a ROOT Session:
```c++
$ .x runAll.cc(dataFilename, mcFilename)
```
dataFilename: a string with the name of the file that has the data events.
mcFilename: a string with the name of the file that has the MC events.

### Systematic Flag Selection
There is flexibility available in choosing systematics. Most systematic flags are found in `LowScaleSystematics.h`. Due
to a minor bug that will be fixed later, the flags for the Scale XYZ systematic are found in `LowScaleSystematics.cpp` in the 
class constructor. The Edep. Fid. Volume flag and the High Energy systematic flag are in `RingFitterEventCombined.cc`. Setting
a flag to true will apply the systematic, and false will omit it.

## Output
- `Systematics.root`: Contains all plots with upper and lower systematic application where needed for MC.
- `SystematicsData.root`: Contains all plots with upper and lower systematic application where needed for Data.
- `FinalPlots.root`: Contains the final plots with Data superimposed on MC. 

