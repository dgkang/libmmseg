/*
 * main.cpp
 *
 *  Created on: 2012-8-1
 *      Author: dgkang
 */

#include "stdio.h"
#include "mmseg.h"

int main(int argc,char**argv)
{
	/*
	if( rmmseg::dict::load_chars("./data/chars.dic") )
	{
		printf("load chars ok.\n");
	}

	if ( rmmseg::dict::load_words("./data/words.dic") )
	{
		printf("load word ok.\n");
	}

	const char * const text = "世界羽联针对昨晚伦敦奥运会羽毛球女双比赛发生的消极比赛事件做出处理决定";
	rmmseg::Algorithm* algorithm = new rmmseg::Algorithm(text,strlen(text));
	if(algorithm)
	{
		for(rmmseg::Token t = algorithm->next_token(); t.text != NULL;t = algorithm->next_token())
		{
				int s = t.text - algorithm->get_text();
				int len  = t.length;
				char str[100] = {0};
				memcpy(str,algorithm->get_text() + s,len);
				printf("%s\n",str);
		}
	}
	return 0;
	*/
	if( !rmmseg::load_default_dic() )
	{
		printf("load default dic failed.\n");
		return 0;
	}

	std::pair<std::vector<std::string>,bool> rt;
	rt = rmmseg::token_utf8_string(argv[1]);
	if(rt.second)
	{
		for(int i = 0; i < rt.first.size(); i++)
		{
			printf("%s\n",rt.first[i].c_str());
		}
	}
}
