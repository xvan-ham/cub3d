# Changelog - Dev Branch

### v0.51
* Added sprite related variables to main program structure (*t_vectors*).
* Added new structure for sprites (*t_sprites*).
* *ft_cub_settings_map_floodcheck.c* now also adds the sprites to the sprite array when the flooding encounters a sprite id on the map.
* Working on sprite array sorting function.

### v0.5
* Added _texture_ info processing in _.cub_ file, including error checking.
* Added _sprite_ info processing in _.cub_ file, including error checking. Sprite will only be loaded if a sprite is present in the map.
* Added _floor_ info processing in _.cub_ file, including error checking.
* Added _ceiling_ info processing in _.cub_ file, including error checking.
* Changed behavior of texture loading in _ft_textures.c_. Program will only load default texture files **if** no value is specified by the user in the _.cub_ file. This will prevent error in case user specifies a file location for a texture and changes or deletes the default texture in the _Textures_ folder.
* Alphabetically ordered variables in *t_texture* (*struct s_texture*) definition in *cub3d.h*.
* Alphabetically ordered variables in *t_vectors (*struct s_vectors*) definition in *cub3d.h*.
* Alphabetically ordered function declarations in *cub3d.h*. 
* Alphabetically ordered source files (_SRCS_) in *Makefile*.
* Current build is completely norminette compliant. 

### v0.45
* Added _resolution_ info processing in _.cub_ file. Performs data validation on the line and checks min max limits of given resolution, adjusting each dimention to the closest allowed value. For instance a resolution width above the established maximum resoution width will adjust the width to the allowed maximum after a console message.
* Included _Textures_ folder into git repository.

### v0.4
* *Restructured* entire codebase to be *more organised* and entirely norminette-compliant. 

### v0.36
* Restructured code layout into folders for clarity. Started initial norminette compliance. Raycasting function broken down for norminette compliance (compliance incomplete as of yet).
* Added flood-fill algorythm to check map-leaks (*ft_cub_settings_map_floodcheck()).
* Added 2 lines in *ft_getmapstr()* (*ft_cub_settings_map_reading.c*) to detect illegal characters in map. 
* Now spawn at centre of a coordinate (before fix it was visually displeasing when there was a wall right in front of spawn).
* Map error-proofing seems to be complete at this stage (further testing required to confirm this).
* Fixed a bug that would occasionally cause the second line of the map to be appended to the first line (whilst still being represented in the second line). This bug had the potential to cause segfaults as malloc'ed heap memory was smaller than copied string (when this bug occurred).
* Fixed getting stuck when strafing sideways into a wall.
* Fixed segfaults in map extremes, functions will check that values don't go beyond matrix limits.

### v0.355
No changes on current dev branch behaviour.
Added a testing environment for flood-fill algorithmn (as a folder) with necessary files.
In this environment, added the following:
* Flood-fill algorythm to check map-leaks.
* Added 2 lines in ft_getmapstr() (ft_cub_settings_map_reading.c) to detect illegal characters in map. 

### v0.35
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

### v0.346	
* Made format changes to version history files (md files).

### v0.345	
* Made format changes to version history files (md files).

### v0.34
* Made format changes to version history files (md files).
* Made changes for raycaster to use new map and sky & floor to be drawn using _R_, _G_, _B_ int values rather than "color".
* *NOT* currently working, still in the middle of changing / testing.


### v0.33		
* Changed map reading and processing to account for valid spaces.
* Added functions to determine width and height (in units) of world map.
* Added function to create a matrix in given dimensions.
* Added search functions in aux.c (will be moved later due to norminette restrictions).
* Added ft_cub_settings_set_settings.c which will parse all lines related with settings (resolutions, paths to textures, etc): TBI.
  - *Note*: frame-drawing has been stopped (with exit(1) in order to test map reading functions).
  - *TBI*:
    * Full map verification.
	* Make raycaster use the newly created map.
	* ft_cub_settings_set_settings.c line parsing for settings	

### v0.32		
* Separated map-reading related code to its own source-code (ft_cub_settings_map_reading).
* Map-reading is now also able to parse orientation letters (N, S, E, W), appart from spaces.
* Added ft_cub_settings_map_create.c to copy the information stored in the str_list and create the char **map that will be read by the raycaster.
* Added ft_cub_settings_map_check.c to validate read map and return error if not valid.
* At the moment this source file only reads the maximum dimensions of the map matrix, it requires a well defined map in order to avoid crash.
	(*TBI*: validate map information before creating map).
* Added null-pointer checks in every function that takes a pointer as an argument in an attempt to locate the occasional segfault - no success.

### v0.31		
* Incorporated .gitignore file to track changes more easily

### v0.3		
* Added map reading capability and necessary utilities such as ft_get_next_line, struct s_str_list to hold tmp_map in a list.
* Added ft_print_tmp_map(t_str_list *tmp_map) to print tmp_map (struct s_str_list) to screen.
