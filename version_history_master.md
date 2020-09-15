# Changelog - Master

### v0.4
* *Restructured* entire codebase to be *more organised* and entirely norminette-compliant. 
* Added flood-fill algorythm to check map-leaks (*ft_cub_settings_map_floodcheck()).
* Added 2 lines in *ft_getmapstr()* (*ft_cub_settings_map_reading.c*) to detect illegal characters in map. 
* Now spawn at centre of a coordinate (before fix it was visually displeasing when there was a wall right in front of spawn).
* Map error-proofing seems to be complete at this stage (further testing required to confirm this).
* Fixed a bug that would occasionally cause the second line of the map to be appended to the first line (whilst still being represented in the second line). This bug had the potential to cause segfaults as malloc'ed heap memory was smaller than copied string (when this bug occurred).
* Fixed getting stuck when strafing sideways into a wall.
* Fixed segfaults in map extremes, functions will check that values don't go beyond matrix limits.

## v0.35
Working raycaster with basic map processing. (Still incomplete but this version is stable)
* Major debugging patch - no more _segfaults_ on launch.
* Fixed a re-curring segfault.
  - Problem lied in texture-loading fuction, malloc for texture (t_texture **) list wass _NOT_ multiplied by *4* to accomodate for the 4 texture pointers (t_texture *) - now corrected.
  - An additional issue was the last pixel of floor was sometimes exceeding array bounds.
* Fixed / implemented working color assignment for sky and floor.
#### Known Issues:
* Getting consistent _segfault_ when crashing into map-edge walls at angles which permit penetrating the wall slightly (establish a maximum ray travel distance).
* Getting stuck on walls is also possible.
* ft_strlen for the first string in tmp_map str_list sometimes gives an excessively large return value.

## v 0.2

* Start of project with working raycaster (ocasional segfault on launch), not enables in this commit.