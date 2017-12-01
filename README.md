# BolzmANN
Neural network in C++ by and for the participants of the [MASIS Programming Class](http://www.masisclass.com), named after the [Boltzmann brain](https://en.wikipedia.org/wiki/Boltzmann_brain).

All network logic is in C++. Some tests are in Python.

# Note to Contributors
BolzmANN is developed using the following environment, tools and technologies:
- [Visual Studio](https://www.visualstudio.com/vs/community/) (always latest, currently 2017)
- Latest C++ (currently 17), more than welcome to use ```std::experimental``` and/or any feature from upcoming standards.
- [Cppcheck](http://cppcheck.sourceforge.net/)
- [Cppcheck Visual Studio add-in](https://marketplace.visualstudio.com/items?itemName=Alexium.Cppcheckadd-in)

Before committing, make sure that:

- Build succeeds with **zero errors** (obviously).
- Build succeeds with **zero warnings related to code** with warning level **/W3** (warnings about profiling are ok).
- Cppcheck ends with **zero warnings** for every project.
- Run produces **expected results**.
- All functional tests **PASS**.
- All code patterns **rhyme** as much as **possible** and **within reason**, meaning this:
```C++
axon_[n].deltaWeight = newDeltaWeight;
axon_[n].weight     += newDeltaWeight;
```
 instead of this:
```C++
axon_[n].deltaWeight = newDeltaWeight;
axon_[n].weight += newDeltaWeight;
```
  
