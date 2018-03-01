#pragma once
#include <string>
#include <vector>

namespace Utilities {
	namespace String {

		// Reverses a string in O(n/2) time by making the minimum number or swaps, 
		// working from the outside in until all characters have been swapped. Three
		// ints are initialized, but swaps are done in place.
		//
		// EX: input = "reverseme"
		// step 1. reverseme --> eeversemr
		//         ^       ^
		// step 2. eeversemr --> emverseer
		//          ^     ^
		// step 3. emverseer --> emeersver
		//           ^   ^
		// step 4. emeersver --> emesrever (Done)
		//            ^ ^
		std::string reverse(std::string input)
		{
			int midpoint = input.length() / 2;

			int start = 0;

			int end = input.length() - 1;

			while (start < midpoint)
			{
				std::swap(input[start], input[end]);

				start++;

				end--;
			}

			return input;
		}

		// Checks a string to see if it contains a character. Returns a vector object 
		// with the locations of each instance of the character, or a null vector object
		// if no instances were found. Runs in O(n) time.
		std::vector<int> contains(std::string haystack, char needle)
		{
			std::vector<int> indices;

			for (int i = 0; i < haystack.length(); i++)
			{
				if (haystack[i] == needle)
				{
					indices.push_back(i);
				}
			}

			return indices;
		}
	}
}