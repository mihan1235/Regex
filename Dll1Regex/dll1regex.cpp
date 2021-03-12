#include "dll1regex.h"
#include <iostream>
#include <stack>
#include <queue>


bool can_get_elem(std::string& input, int i) {
	if (i >= input.size()) {
		return false;
	}
	return true;
}

std::stack<char> make_buf(std::string& input, int i) {
	std::stack<char> buf;
	while (i < input.size()) {
		buf.push(input[i]);
		i++;
	}
	return buf;
}

char pop_elem(std::stack<char>& buf) {
	char c = buf.top();
	buf.pop();
	return c;
}

bool compare_elem(char ic, char c) {
	if (c == '.') return true;
	if (c == ic) return true;
	return false;
}

bool compare_buffers(std::stack<char>& mbuf, std::stack<char>& ibuf) {
	bool asteriks_mod = false;
	while (mbuf.size() != 0) {
		if (mbuf.top() == '*') {
			asteriks_mod = true;
			mbuf.pop();
		}
		else {
			if (mbuf.top() != '*') {
				break;
			}
		}		
	}
	if (mbuf.size() == 0) return true;
	for (int i = 0; i <= mbuf.size(); i++) {
		char c = pop_elem(mbuf);
		if (c == '*') {
			asteriks_mod = true;
			while (mbuf.size() != 0) {
				if (mbuf.top() == '*') {
					mbuf.pop();
				}
				if (mbuf.size() != 0) {
					if (mbuf.top() != '*') {
						if (c == '*') {
							c = pop_elem(mbuf);
						}

						break;
					}
				}
			}
			if (mbuf.size() == 0) {
				return true;
			}
		}
		if (asteriks_mod) {
			bool tmp = false;
			while (ibuf.size() != 0) {
				char ic = pop_elem(ibuf);
				if (compare_elem(ic, c) == true) {
					tmp = true;
					break;
				}
			}
			if (tmp == false) {
				return false;
			}
			asteriks_mod = false;
			continue;
		}
		if (ibuf.size() != 0) {
			char ic = pop_elem(ibuf);
			if (compare_elem(ic, c) != true) {
				return false;
			}
		}
		else {
			return false;
		}
	}
	return true;
}

bool parse(std::string& input, std::string& mask) {
	if (mask.find('*') == std::string::npos) {
		if (input.size() != mask.size()) return false;
	}
	char c;
	int ipos = 0;

	for ( int j= 0; j < mask.size(); j++) {
		c = mask[j];

		if (c =='.') {
			if (can_get_elem(input, ipos)==false) {
				return false;
			}
			ipos++;
			continue;
		}
		if (c == '*') {
			
			std::stack<char> mbuf = make_buf(mask, j);
			std::stack<char> ibuf = make_buf(input, ipos);
			if (compare_buffers(mbuf, ibuf) == true) {
				return true;
			}
			return false;
		}
		if (c != input[ipos]) {
			return false;
		}
		ipos++;
	}
	if (ipos < input.size()) return false;
	return true;
}

void regex(std::istream& in, std::string mask, std::ostream& out) {
	char c;
	std::string str;
	while (!in.eof()) {
		c = in.get();
		if ((c != ' ') && (c != '\t') && (c != '\n') && (c != '\0')) {
			str.push_back(c);
		}
		else {
			if (!str.empty()) {
				//auto var = split_mask(mask);
				if (parse(str, mask)) {
					out.write(str.c_str(), str.size());
					out.put('\n');
				}
				out.flush();
				str.erase();
			}			
		}
	}
}





