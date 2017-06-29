#include "common.h"
#include "color.h"
#include "board.h"
#include "draw.h"
#include "string.h"

void exportToBMP(const char *filename) {
	int fileSize = 54 + 3 * WIDTH * HEIGHT;
	size_t imgSize = 3 * WIDTH * HEIGHT;
	uint8_t *img = new uint8_t[imgSize];
	memset(img, 0, imgSize);

	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			int color = board.color[i][j];
			int r = (color >> 16) & 0xFF;
			int g = (color >> 8) & 0xFF;
			int b = color & 0xFF;
			size_t offset = (i + (HEIGHT - 1 - j) * WIDTH) * 3;
			img[offset + 2] = (uint8_t)r;
			img[offset + 1] = (uint8_t)g;
			img[offset + 0] = (uint8_t)b;
		}
	}

	uint8_t bmpHeader[14] = { 'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0 };
	uint8_t bmpInfoHeader[40] = { 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0 };

	*(uint32_t *)(bmpHeader + 2) = (uint32_t)fileSize;
	*(uint32_t *)(bmpInfoHeader + 4) = (uint32_t)WIDTH;
	*(uint32_t *)(bmpInfoHeader + 8) = (uint32_t)HEIGHT;

	FILE *file = fopen(filename, "wb");
	fwrite(bmpHeader, 1, 14, file);
	fwrite(bmpInfoHeader, 1, 40, file);
	for (int i = 0; i < HEIGHT; i++) {
		size_t offset = ((HEIGHT - i - 1) * WIDTH) * 3;
		fwrite(img + offset, 3, (size_t)WIDTH, file);
	}
	fclose(file);
	delete[] img;
	puts("Export succeed");
}

void importFromBMP(const char *filename) {
	FILE *file = fopen(filename, "rb");
	if (file) {
		uint8_t info[54];
		fread(info, sizeof(uint8_t), 54, file);
		int imgOffset = *(int *)(info + 10);
		uint32_t width = *(uint32_t *)(info + 18);
		uint32_t height = *(uint32_t *)(info + 22);
		size_t imgSize = 3 * width * height;

		uint8_t *img = new uint8_t[imgSize];
		fseek(file, imgOffset, SEEK_SET);
		fread(img, sizeof(uint8_t), imgSize, file);
		fclose(file);

		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < HEIGHT; j++) {
				int color = COLOR_BACKGROUND;
				int diff = (int)HEIGHT - height;
				if ((i < width) && (j > diff)) {
					size_t offset = (i + (j - diff) * width) * 3;
					color = (*(int *)(img + offset)) & 0xFFFFFF;
				}
				Point(i, j).draw(color);
			}
		}
		delete[] img;
		glFlush();
		puts("Import succeed");
	}
	else {
		puts("File not exist");
	}
}

char *readFilename() {
	puts("Please input filename (*.bmp)");
	static char s[32];
	scanf("%s", s);
	size_t len = strlen(s);
	if (!((len > 4) && (strcmp(s + len - 4, ".bmp") == 0))) {
		strcat(s + len, ".bmp");
	}
	return s;
}

void cmdImport() {
	char *s = readFilename();
	importFromBMP(s);
}

void cmdExport() {
	char *s = readFilename();
	exportToBMP(s);
}

