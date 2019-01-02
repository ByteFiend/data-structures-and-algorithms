type TrieNode struct {
	next map[rune]*TrieNode
	isEndOfWord bool
}

type Trie struct {
	root *TrieNode
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{&TrieNode{make(map[rune]*TrieNode), false}}
}


/** Inserts a word into the trie. */
func (this *Trie) Insert(word string)  {
	if 0 == len(word) { return }

	cur := this.root
	for _, c := range word {
		next, ok := cur.next[c]
		if !ok {
			cur.next[c] = &TrieNode{make(map[rune]*TrieNode), false}
			next = cur.next[c]
		}
		cur = next
	}
	cur.isEndOfWord = true
}


/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	if 0 == len(word) { return false }

	cur := this.root
	for _, c := range word {
		next, ok := cur.next[c]
		if !ok { return false }
		cur = next
	}

	return cur.isEndOfWord
}


/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	if 0 == len(prefix) { return false }

	cur := this.root
	for _, c := range prefix {
		next, ok := cur.next[c]
		if !ok { return false }
		cur = next
	}

	return true
}


/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
