#pragma once

#include <string>
void open_file_browser();
void setup_file_open();
void setup_file_save();

// sets up menubar functions
void setup_menubar();

void load_from_file_into_editor(const std::string &file_path);
void save_file();
