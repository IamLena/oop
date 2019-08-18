#pragma once
#include <exception>

namespace error {
	class CommonError : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "error";
		}
	};

	class ZeroSizeError : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Zero_Size_Error";
		}
	};
	class SizeDismatch : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Size_Dismatch";
		}
	};

	class MemmoryError : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Memmory_Error";
		}
	};

	class IndexError : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Index_Error";
		}
	};

	class TooMuchDimentions : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Too_Much_Dimentions";
		}
	};
}