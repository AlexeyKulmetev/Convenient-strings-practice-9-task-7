#include "TString.h"


TString::TString(int l) {
	len = l;
	if (l > 0) {
		s = new (std::nothrow) char[l + 1];
		*s = '\0';
	}
}

TString::TString(const TString& sample) {
	len = sample.len;
	s = new (std::nothrow) char[len + 1];
	for (int i = 0; i <= len; i++) {
		s[i] = sample.s[i];
	}
}

TString::TString(const char* str) {
	if (s != nullptr) {
		delete[] s;
		s = nullptr;
	}
	len = 0;
	for (; str[len] != '\0'; len++);
	s = new (std::nothrow) char[len + 1];
	if (nullptr == s) {
		len = 0;
	}
	for (int i = 0; i <= len; i++)
		s[i] = str[i];
}

std::ostream& operator << (std::ostream& out, const TString& str) {
	if (str.s != nullptr)
		return out << str.s;
	else
		return out;
}

TString& TString::operator = (const TString str)
{
	if (this != &str) {
		if (s != nullptr) {
			delete[] s;
			s = nullptr;
		}
		len = str.len;
		s = new (std::nothrow) char[len + 1];
		if (s == nullptr) {
			len = 0;
			return *this;
		}
		for (int i = 0; i <= len; i++ ) {
			s[i] = str.s[i];
		}
	}
	return *this;
}

TString TString::operator + (const TString& str)
{
	if (str.len <= 0)
		return *this;
	char* tmpS = new (std::nothrow) char[len + str.len + 1];
	if (nullptr == tmpS)
		return *this;
	for (int i = 0; i < len; i++) {
		tmpS[i] = s[i];
	}
	for (int i = 0; i <= str.len; i++) {
		tmpS[len + i] = str.s[i];
	}
	TString result(tmpS);
	delete tmpS;
	return result;
}

bool TString::operator == (const TString& str)
{
	int i = 0;
	while (str.s[i] != '\0' && s[i] != '\0' && i <= len && i <= str.len) {
		if (s[i] != str.s[i])
			return false;
		i++;
	}
	if (i == len && i == str.len)
		return true;
	else
		return false;
}

bool TString::operator != (const TString& str)
{
	int i = 0;
	while (str.s[i] != '\0' && s[i] != '\0' && i <= len && i <= str.len) {
		if (s[i] != str.s[i])
			return true;
		i++;
	}
	if (i == len && i == str.len)
		return false;
	else
		return true;
}

bool TString::operator < (const TString& str)
{
	for (int i = 0; s[i] != '\0', str.s[i] != '\0', i <= len, i <= str.len; i++) {
		if (s[i] < str.s[i])
			return true;
		if (s[i] > str.s[i])
			return false;
	}
	if (len < str.len)
		return true;
	return false;
}

bool TString::operator <= (const TString& str)
{
	for (int i = 0; s[i] != '\0', str.s[i] != '\0', i <= len, i <= str.len; i++) {
		if (s[i] < str.s[i])
			return true;
		if (s[i] > str.s[i])
			return false;
	}
	if (len > str.len)
		return false;
	return true;
}

bool TString::operator > (const TString& str) {
	for (int i = 0; s[i] != '\0', str.s[i] != '\0', i <= len, i <= str.len; i++) {
		if (s[i] > str.s[i])
			return true;
		if (s[i] < str.s[i])
			return false;
	}
	if (len > str.len)
		return true;
	return false;
}

bool TString::operator >= (const TString& str) {
	for (int i = 0; s[i] != '\0', str.s[i] != '\0', i <= len, i <= str.len; i++) {
		if (s[i] > str.s[i])
			return true;
		if (s[i] < str.s[i])
			return false;
	}
	if (len < str.len)
		return false;
	return true;
}