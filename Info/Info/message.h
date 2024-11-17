#pragma once
#include <string>

namespace Message {
	const std::string PROGRAM_NAME{ "Info" };
	const std::string SLOGAN{ "Look for everything you want to keep" };
	const std::string WAIT_INPUT{ "Waiting for input: " };
	const std::string WAIT_INPUT_NEWLINE{ "Waiting for input\n: " };
	const std::string GO_NEXT_PAGE{ "Go to the next page" };
	const std::string GO_PREV_PAGE{ "Go to the previous page" };
	const std::string RETURN_HOME{ "Return home" };
	const std::string EXIT_PROGRAM{ "Exit program" };
	const std::string CREATE_INFO{ "Create new info" };
	const std::string UPDATE_INFO{ "Update info" };
	const std::string DELETE_INFO{ "Delete info" };
	const std::string SAVE_INFO{ "Save info" };
	const std::string SEARCH_INFO{ "Search" };
	const std::string PRESS_ID{ "Type in info id to read, update, and delete your info" };
	const std::string GUIDE_CREATE_INFO{ "Write { title }; { author }; { type }; { published year }; { summary }; { link }.\nLeave the field blank if you do not wish to fill in. (e.g Hong Gildong; Heo Gyun; Book;;)" };
	const std::string GUIDE_SAVE_INFO{ "Are you sure you want to save this info? (y/n)" };
	const std::string GUIDE_UPDATE_INFO{ "Write { field name };{ value to be updated } (e.g.title;New Title) to update your info." };
	const std::string GUIDE_DELETE_INFO{ "Are you sure you want to delete this info? (y/n)" };
	const std::string SUCCESS_DELETE_INFO{ "Successfully deleted your info." };
	const std::string SUCCESS_SAVE_INFO{ "Successfully saved your info." };
	const std::string INVALID_INPUT{ "Invalid input. Please try again." };
};
