/*
 * Copyright 2017 Akshay Agarwal, agarwal.akshay.akshay8@gmail.com
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef CATEGORY_H
#define CATEGORY_H

#include <GraphicsDefs.h>
#include <String.h>
#include <Uuid.h>

#include "ColorConverter.h"


class Category {
public:
		enum CategorySource {
			LOCAL,
			GOOGLE
		};

		Category(BString name, rgb_color color,
			const char* id = BUuid().SetToRandom().ToString(),
			CategorySource source = CategorySource::LOCAL);
		Category(BString name, BString color,
			const char* id = BUuid().SetToRandom().ToString(),
			CategorySource source = CategorySource::LOCAL);
		Category(Category& category);

		BString GetName();
		rgb_color GetColor();
		BString GetHexColor();
		const char* GetId();
		CategorySource GetSource();

		bool Equals(Category &c);

private:
		BString			fId;
		BString 		fName;
		rgb_color 		fColor;
		CategorySource	fSource;

};

#endif
