# Changelog - Master

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