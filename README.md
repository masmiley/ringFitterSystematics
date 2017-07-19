# ringFitterSystematics
Atmospheric Systematic Propagation for the SNO experiment. Applies High Low Energy Systematics to MC Data.

## Use
In a ROOT Session:
```c++
$ .x runAll.cc(USEWATER, filename)
```
int USEWATER = 1 or D2O, 0 otherwise. 
std::string filename = name of file from which events tree is to be read.

### Systematic Flag Selection
There is flexibility available in choosing systematics. Most systematic flags are found in `LowScaleSystematics.h`. Due
to a minor bug that will be fixed later, the flags for the Scale XYZ systematic are found in `LowScaleSystematics.cpp` in the 
class constructor. The Edep. Fid. Volume flag and the High Energy systematic flag are in `RingFitterEventCombined.cc`. Setting
a flag to true will apply the systematic, and false will omit it.

## Output
- `Systematics.root`: Contains all final plots with upper and lower systematic application where needed.
- `MC_CombinedSystematicNominal.root`: Contains just the nominal plots.
- `MC_CombinedSystematicUpper.root`: Contains just the upper plots.
- `MC_CombinedSystematicLower.root`: Contains just the lower plots.
