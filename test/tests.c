#include <stdio.h>
#include <string.h>
#include "ctest.h"
#include "search.h"

CTEST(Search, GetFileNames_ReturnsTest_c) {
	char path[] = "TestData/";
	NameOfFiles(path);
	
	FILE *NamesOfFiles = fopen("TestData/NamesOfFiles.txt", "r");
	char fileData[1][256];
	while(!feof(NamesOfFiles)) {
		fscanf(NamesOfFiles, "%s", fileData[0]);
	}
	ASSERT_STR(fileData[0], "test.c");
}

CTEST(Search, GetFileNames_ReturnsMinusOne) {
	char path[] = "TestDatasz/";
	int test = NameOfFiles(path);
	
	ASSERT_EQUAL(test, -1);
}

CTEST(Search, Search_GetIntMainVoid) {
	char findStr[] = "int main(void)";
	char path[] = "TestData/";
	
	Search(path, findStr);
}