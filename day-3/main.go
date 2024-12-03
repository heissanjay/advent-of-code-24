package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strconv"
	"strings"
)

func findMultiples(input string) int {
	pattern := `mul\(\d{1,3},\d{1,3}\)`
	re := regexp.MustCompile(pattern)
	sum := 0
	valid := re.FindAllString(input, -1)
	for _, ins := range valid {
		operands := ins[4 : len(ins)-1]
		parts := strings.Split(operands, ",")
		if len(parts) == 2 {
			op1, err1 := strconv.Atoi(parts[0])
			op2, err2 := strconv.Atoi(parts[1])
			if err1 == nil && err2 == nil {
				sum += op1 * op2
			}
		}
	}
	return sum
}

func findProducts(input string) int {
	sum := 0
	enabled := true
	pattern := `(do\(\)|don't\(\)|mul\(\d{1,3},\d{1,3}\))`
	re := regexp.MustCompile(pattern)
	matches := re.FindAllString(input, -1)

	for _, match := range matches {
		switch match {
		case "do()":
			enabled = true
		case "don't()":
			enabled = false
		default:
			if enabled && strings.HasPrefix(match, "mul(") {
				operands := match[4 : len(match)-1]
				parts := strings.Split(operands, ",")
				op1, _ := strconv.Atoi(parts[0])
				op2, _ := strconv.Atoi(parts[1])
				sum += op1 * op2
			}
		}
	}
	return sum
}

func main() {
	file, err := os.Open("input.txt")
	if err != nil {
		panic("Error opening file")
	}

	defer file.Close()
	input := ""
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		input += scanner.Text()
	}

	sum := findProducts(input)
	fmt.Println(sum)

}
