package comb

import (
	"sort"
	"testing"
)

// 順番を無視して、文字列スライスを比較する
func equals(s1, s2 []string) bool {

	// ソートして順番を揃える
	sort.StringSlice(s1).Sort()
	sort.StringSlice(s2).Sort()

	if len(s1) != len(s2) {
		return false
	}

	for i := range s1 {
		if s1[i] != s2[i] {
			return false
		}
	}

	return true
}

// 期待した組み合せのスライスの中にあるか？
func indexOf(expects [][]string, actual []string) int {

	for i, expect := range expects {
		if equals(expect, actual) {
			return i
		}
	}

	return -1
}

// 組み合せのテスト
func TestComb(t *testing.T) {

	// 組み合せを作る元となる文字列のスライス
	strs := []string{"A", "B", "C", "D", "E"}

	// 期待する組み合せのスライス
	expects := [][]string{
		{"A", "B"},
		{"A", "C"},
		{"B", "C"},
		{"A", "D"},
		{"B", "D"},
		{"C", "D"},
		{"A", "E"},
		{"B", "E"},
		{"C", "E"},
		{"D", "E"},
	}

	// 2つずつ取り出す組み合せ
	for combIdx := range CombinationGenerator(len(strs), 2) {

		// 実際の値
		var actual []string
		combIdx.Index(strs, &actual)

		// 期待する組み合せに含まれているか？
		if i := indexOf(expects, actual); i < 0 {
			t.Errorf("組み合せが不正か同じ組み合せが複数あります。")
		} else {
			// すでに見つかったので削除する
			expects = append(expects[:i], expects[i+1:]...)
		}
	}

	// すべて出たか？
	if len(expects) > 0 {
		t.Errorf("すべての組み合せが列挙されていません。")
	}
}
