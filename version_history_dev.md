# Changelog - Dev Branch

## v0.346	
* Made format changes to version history files (md files).

## v0.345	
* Made format changes to version history files (md files).

## v0.34
* Made format changes to version history files (md files).
* Made changes for raycaster to use new map and sky & floor to be drawn using R, G, B int values rather than "color".
* *NOT* currently working, still in the middle of changing / testing.


## v0.33		
* Changed map reading and processing to account for valid spaces.
* Added functions to determine width and height (in units) of world map.
* Added function to create a matrix in given dimensions.
* Added search functions in aux.c (will be moved later due to norminette restrictions).
* Added ft_cub_settings_set_settings.c which will parse all lines related with settings (resolutions, paths to textures, etc): TBI.
	*Note*: frame-drawing has been stopped (with exit(1) in order to test map reading functions).
	*TBI*:
	* Full map verification.
	* Make raycaster use the newly created map.
	* ft_cub_settings_set_settings.c line parsing for settings	

## v0.32		
* Separated map-reading related code to its own source-code (ft_cub_settings_map_reading).
* Map-reading is now also able to parse orientation letters (N, S, E, W), appart from spaces.
* Added ft_cub_settings_map_create.c to copy the information stored in the str_list and create the char **map that will be read by the raycaster.
* Added ft_cub_settings_map_check.c to validate read map and return error if not valid.
* At the moment this source file only reads the maximum dimensions of the map matrix, it requires a well defined map in order to avoid crash.
	(*TBI*: validate map information before creating map).
* Added null-pointer checks in every function that takes a pointer as an argument in an attempt to locate the occasional segfault - no success.

## v0.31		
* Incorporated .gitignore file to track changes more easily

## v0.3		
* Added map reading capability and necessary utilities such as ft_get_next_line, struct s_str_list to hold tmp_map in a list.
* Added ft_print_tmp_map(t_str_list *tmp_map) to print tmp_map (struct s_str_list) to screen.