# Change Log
This document reflects this current commit's state and not just its version. All items listed below were implemented for this commit.

## Version v1.0.1
This hot fixed involved a issue with the `distance` function attempting to be accessed from the wrong lib(`cmath`).

### Addition
- None

### Changes
- None

### Fixes
- The `distance` function in `item1_using_std_namespace_is_fine` was incorrectly included assuming it was from `cmath` library when in fact it is from `iterator` library. This would have caused an error if the code was to be corrected. The code now uses the correct function from the correct library so if you correct code from ambiguity, it will work.