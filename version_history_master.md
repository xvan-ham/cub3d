# Changelog - Master

### v1.03
* Fixed an issue when a portion of map is isolated and contains sprites (in the isolated section). Now map does not render nor make calculations on sprites located in an isolated portions of the map (not accessible to player by walking).
* Updated *README*.

### v1.025
* Deleted test source-file *dummy.c*.

### v1.02
* Placed source files in folders as it was in _v1.0_.
* Changed Makefile to work correctly with folder structure.

### v1.01
* Adapted Makefile for project delivery.

### v1.0
* Fixed a bug that could result in segfault (*tex_pos* could have value -1).
* Cub file error handling has been extensively tested.
* Added screenshot capability!
* Fixed all runtime memory leaks.
* Cleaned/restructured source code for norminette compliance (added *ft_sprites_sort.c*).
* Fixed memory when freeing *get_next_line* lines.
* Added 2 constants to *ft_cub3d.h*: _VERBOSE_; *PRINT_MAPS*. If these are changed from _0_ to _1_, they will print extra program info during runtime and all the intermediary maps in case of the latter.
* Now represents sprites correcly (not norminette compliant - still needs doing).
* Added fully functional sprite-sorting algorithm.
* Added sprite related variables to main program structure (*t_vectors*).
* Added new structure for sprites (*t_sprites*).
* *ft_cub_settings_map_floodcheck.c* now also adds the sprites to the sprite array when the flooding encounters a sprite id on the map.

### v0.5
* Added _texture_ info processing in _.cub_ file, including error checking.
* Added _sprite_ info processing in _.cub_ file, including error checking. Sprite will only be loaded if a sprite is present in the map.
* Added _floor_ info processing in _.cub_ file, including error checking.
* Added _ceiling_ info processing in _.cub_ file, including error checking.
* Added _resolution_ info processing in _.cub_ file. Performs data validation on the line and checks min max limits of given resolution, adjusting each dimention to the closest allowed value. For instance a resolution width above the established maximum resoution width will adjust the width to the allowed maximum after a console message.
* Included _Textures_ folder into git repository.
* Changed behavior of texture loading in _ft_textures.c_. Program will only load default texture files **if** no value is specified by the user in the _.cub_ file. This will prevent error in case user specifies a file location for a texture and changes or deletes the default texture in the _Textures_ folder.
* Alphabetically ordered variables in *t_texture* (*struct s_texture*) definition in *cub3d.h*.
* Alphabetically ordered variables in *t_vectors (*struct s_vectors*) definition in *cub3d.h*.
* Alphabetically ordered function declarations in *cub3d.h*. 
* Alphabetically ordered source files (_SRCS_) in *Makefile*.
* Current build is completely norminette compliant. 

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