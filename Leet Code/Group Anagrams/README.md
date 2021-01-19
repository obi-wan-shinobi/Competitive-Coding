# Problem

Given an array of strings `strs`, group __the anagrams__ together. You can return the answer in __any order__.

An __Anagram__ is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

#### Example 1:
```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

#### Example 2:
```
Input: strs = [""]
Output: [[""]]
```

#### Example 3
```
Input: strs = ["a"]
Output: [["a"]]
```

### Constraints:

- <code>1 <= strs.length <= 10<sup>4</sup></code>
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lower-case English letters.
