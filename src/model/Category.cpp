/*
 * Copyright 2017 Akshay Agarwal, agarwal.akshay.akshay8@gmail.com
 * All rights reserved. Distributed under the terms of the MIT license.
 */

#include "Category.h"

#include <stdio.h>
#include <stdlib.h>

#include <Uuid.h>

#include "ColorConverter.h"

Category::Category(BString name, rgb_color color,
	const char* id, CategorySource source)
	:
	fId(id),
	fName(name),
	fColor(color),
	fSource(source)
{
}


Category::Category(BString name, BString color,
	const char* id, CategorySource source)
	:
	fId(id),
	fName(name),
	fColor(HexToRGB(color)),
	fSource(source)
{
}


Category::Category(Category &category)
{
	fName = category.GetName();
	fColor = category.GetColor();
	fId = category.GetId();
}


BString
Category::GetName()
{
	return fName;
}


rgb_color
Category::GetColor()
{
	return fColor;
}


BString
Category::GetHexColor()
{
	return RGBToHex(fColor);
}


const char*
Category::GetId()
{
	return fId.String();
}

Category::CategorySource
Category::GetSource()
{
	return fSource;
}


bool
Category::Equals(Category &c)
{
	return (fId == c.GetId());
}
