/*

    File: parti386.h

    Copyright (C) 2009 Christophe GRENIER <grenier@cgsecurity.org>
  
    This software is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
  
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
  
    You should have received a copy of the GNU General Public License along
    with this program; if not, write the Free Software Foundation, Inc., 51
    Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

 */
#ifdef __cplusplus
extern "C" {
#endif

/*@
  @ requires \valid_read(disk_car);
  @ requires \valid_read(partition);
  @ assigns \nothing;
  @*/
int parti386_can_be_ext(const disk_t *disk_car, const partition_t *partition);

/*@
  @ requires \valid(disk_car);
  @ requires list_part == \null || \valid_read(list_part);
  @ requires \valid(current_cmd);
  @ requires valid_read_string(*current_cmd);
  @ requires separation: \separated(disk_car, list_part, current_cmd);
  @ ensures  valid_read_string(*current_cmd);
  @*/
list_part_t *add_partition_i386_cli(disk_t *disk_car, list_part_t *list_part, char **current_cmd);

/*@
  @ requires \valid(disk);
  @ requires \valid_read(buffer + (0 .. 512-1));
  @ requires \valid(partition);
  @ requires separation: \separated(disk, buffer + (0 .. 512-1), partition);
  @*/
int recover_i386_logical(disk_t *disk, const unsigned char *buffer, partition_t *partition);

#ifdef __cplusplus
} /* closing brace for extern "C" */
#endif
