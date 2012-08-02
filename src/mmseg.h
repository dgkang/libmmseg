/*
 * mmseg.h
 *
 *  Created on: 2012-8-2
 *      Author: dgkang
 */

#ifndef MMSEG_H_
#define MMSEG_H_
#include <string>
#include <vector>

namespace rmmseg
{
	bool load_default_dic();
	bool load_dic_for_path(const std::string& s);
	std::pair<std::vector<std::string>,bool> token_utf8_string(const std::string& s);
}

#endif /* MMSEG_H_ */
