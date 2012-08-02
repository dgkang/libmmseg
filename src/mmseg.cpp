/*
 * mmseg.cpp
 *
 *  Created on: 2012-8-2
 *      Author: dgkang
 */
#include "mmseg.h"
#include "token.h"
#include "dict.h"
#include "algor.h"

namespace rmmseg
{

	bool load_dic_for_path(const std::string& s)
	{
		if( !rmmseg::dict::load_chars( (s + "/chars.dic").c_str() )
				|| !rmmseg::dict::load_words((s + "/words.dic").c_str()) )
			return false;
		return true;
	}

	bool load_default_dic()
	{
		return load_dic_for_path("./dic");
	}

	std::pair<std::vector<std::string>,bool> token_utf8_string(const std::string& s)
	{
		std::vector<std::string> rvt;
		rmmseg::Algorithm* algorithm = new rmmseg::Algorithm(s.c_str(),s.length());
		if(algorithm)
		{
			for(rmmseg::Token t = algorithm->next_token(); t.text != NULL;t = algorithm->next_token())
			{
				std::string str;
				int s = t.text - algorithm->get_text();
				int len  = t.length;
				str.assign(algorithm->get_text() + s,len);
				rvt.push_back(str);
			}
			delete algorithm;
			return std::pair<std::vector<std::string>,bool>(rvt,true);
		}
		return std::pair<std::vector<std::string>,bool>(rvt,false);
	}
}

