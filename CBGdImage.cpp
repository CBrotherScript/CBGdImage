#include "ICBModule.h"

#include <string.h>
#include <stdio.h>

#include <gd.h>
#include <gdfontg.h>
#include <gdfontl.h>
#include <gdfontt.h>
#include <gdfonts.h>
#include <gdfontmb.h>

ICBObject* CBGdImage_Init(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	return NULL;
}

void CBGdImage_Release(ICBrother* pCBrother,IClassObject* obj,int releaseType)
{
	if (releaseType != CB_RELEASE)
	{
		return;
	}

	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im != NULL)
	{
		gdImageDestroy(im);
	}
}

ICBObject* CBGdImage_gdImageCreate(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im != NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is already created.");
		return NULL;
	}

	ICBObject* sxObj = args.GetCBObject(0);
	ICBObject* syObj = args.GetCBObject(1);
	if (sxObj == NULL || syObj == NULL)
	{
		return pCBrother->CreateCBObject(false);
	}

	int sx = sxObj->AnyTypeToInt();
	int sy = syObj->AnyTypeToInt();
	im = gdImageCreate(sx,sy);
	obj->SetUserParm(im);
	return pCBrother->CreateCBObject(im != NULL);
}

ICBObject* CBGdImage_gdImageCreateTrueColor(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im != NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is already created.");
		return NULL;
	}

	ICBObject* sxObj = args.GetCBObject(0);
	ICBObject* syObj = args.GetCBObject(1);
	if (sxObj == NULL || syObj == NULL)
	{
		return pCBrother->CreateCBObject(false);
	}

	int sx = sxObj->AnyTypeToInt();
	int sy = syObj->AnyTypeToInt();
	im = gdImageCreateTrueColor(sx,sy);
	obj->SetUserParm(im);
	return pCBrother->CreateCBObject(im != NULL);
}

ICBObject* CBGdImage_gdImageColorAllocate(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* rObj = args.GetCBObject(0);
	ICBObject* gObj = args.GetCBObject(1);
	ICBObject* bObj = args.GetCBObject(2);
	if (rObj == NULL || gObj == NULL || bObj == NULL)
	{
		return pCBrother->CreateCBObject(-1);
	}

	int r = rObj->AnyTypeToInt();
	int g = gObj->AnyTypeToInt();
	int b = bObj->AnyTypeToInt();
	int ci = gdImageColorAllocate(im,r,g,b);
	return pCBrother->CreateCBObject(ci);
}

ICBObject* CBGdImage_gdImageColorAllocateAlpha(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* rObj = args.GetCBObject(0);
	ICBObject* gObj = args.GetCBObject(1);
	ICBObject* bObj = args.GetCBObject(2);
	ICBObject* aObj = args.GetCBObject(3);
	if (rObj == NULL || gObj == NULL || bObj == NULL || aObj == NULL)
	{
		return pCBrother->CreateCBObject(-1);
	}

	int r = rObj->AnyTypeToInt();
	int g = gObj->AnyTypeToInt();
	int b = bObj->AnyTypeToInt();
	int a = aObj->AnyTypeToInt();
	int ci = gdImageColorAllocateAlpha(im,r,g,b,a);
	return pCBrother->CreateCBObject(ci);
}

ICBObject* CBGdImage_gdImageArc(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* cxObj = args.GetCBObject(0);
	ICBObject* cyObj = args.GetCBObject(1);
	ICBObject* wObj = args.GetCBObject(2);
	ICBObject* hObj = args.GetCBObject(3);
	ICBObject* sObj = args.GetCBObject(4);
	ICBObject* eObj = args.GetCBObject(5);
	ICBObject* colorObj = args.GetCBObject(6);
	if (cxObj == NULL || cyObj == NULL || wObj == NULL || hObj == NULL || sObj == NULL || eObj == NULL || colorObj == NULL)
	{
		return pCBrother->CreateCBObject(false);
	}

	int cx = cxObj->AnyTypeToInt();
	int cy = cyObj->AnyTypeToInt();
	int w = wObj->AnyTypeToInt();
	int h = hObj->AnyTypeToInt();
	int s = sObj->AnyTypeToInt();
	int e = eObj->AnyTypeToInt();
	int color = colorObj->AnyTypeToInt();

	gdImageArc(im,cx,cy,w,h,s,e,color);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageFilledArc(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* cxObj = args.GetCBObject(0);
	ICBObject* cyObj = args.GetCBObject(1);
	ICBObject* wObj = args.GetCBObject(2);
	ICBObject* hObj = args.GetCBObject(3);
	ICBObject* sObj = args.GetCBObject(4);
	ICBObject* eObj = args.GetCBObject(5);
	ICBObject* colorObj = args.GetCBObject(6);
	ICBObject* styleObj = args.GetCBObject(7);
	if (cxObj == NULL || cyObj == NULL || wObj == NULL || hObj == NULL || sObj == NULL || eObj == NULL || colorObj == NULL || styleObj == NULL)
	{
		return pCBrother->CreateCBObject(false);
	}

	int cx = cxObj->AnyTypeToInt();
	int cy = cyObj->AnyTypeToInt();
	int w = wObj->AnyTypeToInt();
	int h = hObj->AnyTypeToInt();
	int s = sObj->AnyTypeToInt();
	int e = eObj->AnyTypeToInt();
	int color = colorObj->AnyTypeToInt();
	int style = styleObj->AnyTypeToInt();

	gdImageFilledArc(im,cx,cy,w,h,s,e,color,style);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageEllipse(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* cxObj = args.GetCBObject(0);
	ICBObject* cyObj = args.GetCBObject(1);
	ICBObject* wObj = args.GetCBObject(2);
	ICBObject* hObj = args.GetCBObject(3);
	ICBObject* colorObj = args.GetCBObject(4);
	if (cxObj == NULL || cyObj == NULL || wObj == NULL || hObj == NULL || colorObj == NULL)
	{
		return pCBrother->CreateCBObject(false);
	}

	int cx = cxObj->AnyTypeToInt();
	int cy = cyObj->AnyTypeToInt();
	int w = wObj->AnyTypeToInt();
	int h = hObj->AnyTypeToInt();
	int color = colorObj->AnyTypeToInt();

	gdImageEllipse(im,cx,cy,w,h,color);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageFilledEllipse(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* cxObj = args.GetCBObject(0);
	ICBObject* cyObj = args.GetCBObject(1);
	ICBObject* wObj = args.GetCBObject(2);
	ICBObject* hObj = args.GetCBObject(3);
	ICBObject* colorObj = args.GetCBObject(4);
	if (cxObj == NULL || cyObj == NULL || wObj == NULL || hObj == NULL || colorObj == NULL)
	{
		return pCBrother->CreateCBObject(false);
	}

	int cx = cxObj->AnyTypeToInt();
	int cy = cyObj->AnyTypeToInt();
	int w = wObj->AnyTypeToInt();
	int h = hObj->AnyTypeToInt();
	int color = colorObj->AnyTypeToInt();

	gdImageFilledEllipse(im,cx,cy,w,h,color);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageRectangle(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* x1Obj = args.GetCBObject(0);
	ICBObject* y1Obj = args.GetCBObject(1);
	ICBObject* x2Obj = args.GetCBObject(2);
	ICBObject* y2Obj = args.GetCBObject(3);
	ICBObject* colorObj = args.GetCBObject(4);
	if (x1Obj == NULL || y1Obj == NULL || x2Obj == NULL || y2Obj == NULL || colorObj == NULL)
	{
		return pCBrother->CreateCBObject(false);
	}

	int x1 = x1Obj->AnyTypeToInt();
	int y1 = y1Obj->AnyTypeToInt();
	int x2 = x2Obj->AnyTypeToInt();
	int y2 = y2Obj->AnyTypeToInt();
	int color = colorObj->AnyTypeToInt();

	gdImageRectangle(im,x1,y1,x2,y2,color);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageFilledRectangle(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* x1Obj = args.GetCBObject(0);
	ICBObject* y1Obj = args.GetCBObject(1);
	ICBObject* x2Obj = args.GetCBObject(2);
	ICBObject* y2Obj = args.GetCBObject(3);
	ICBObject* colorObj = args.GetCBObject(4);
	if (x1Obj == NULL || y1Obj == NULL || x2Obj == NULL || y2Obj == NULL || colorObj == NULL)
	{
		return pCBrother->CreateCBObject(false);
	}

	int x1 = x1Obj->AnyTypeToInt();
	int y1 = y1Obj->AnyTypeToInt();
	int x2 = x2Obj->AnyTypeToInt();
	int y2 = y2Obj->AnyTypeToInt();
	int color = colorObj->AnyTypeToInt();

	gdImageFilledRectangle(im,x1,y1,x2,y2,color);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageFillToBorder(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* x1Obj = args.GetCBObject(0);
	ICBObject* y1Obj = args.GetCBObject(1);
	ICBObject* borderObj = args.GetCBObject(2);
	ICBObject* colorObj = args.GetCBObject(3);
	if (x1Obj == NULL || y1Obj == NULL || borderObj == NULL || colorObj == NULL)
	{
		return pCBrother->CreateCBObject(false);
	}

	int x1 = x1Obj->AnyTypeToInt();
	int y1 = y1Obj->AnyTypeToInt();
	int border = borderObj->AnyTypeToInt();
	int color = colorObj->AnyTypeToInt();

	gdImageFillToBorder(im,x1,y1,border,color);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageFill(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* x1Obj = args.GetCBObject(0);
	ICBObject* y1Obj = args.GetCBObject(1);
	ICBObject* colorObj = args.GetCBObject(2);
	if (x1Obj == NULL || y1Obj == NULL || colorObj == NULL)
	{
		return pCBrother->CreateCBObject(false);
	}

	int x1 = x1Obj->AnyTypeToInt();
	int y1 = y1Obj->AnyTypeToInt();
	int color = colorObj->AnyTypeToInt();

	gdImageFill(im,x1,y1,color);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageCopy(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* srcObj = args.GetCBObject(0);
	if (srcObj == NULL || srcObj->Type() != CB_CLASS)
	{
		pException = pCBrother->CreateException("GDImageException","src is not gd::Image object.");
		return NULL;
	}

	IClassObject* clsObj = srcObj->ClassObjValue();
	if (strcmp(clsObj->GetCBClassName(),"gd::Image") != 0)
	{
		pException = pCBrother->CreateException("GDImageException","src is not gd::Image object.");
		return NULL;
	}

	ICBObject* dstXObj = args.GetCBObject(1);
	ICBObject* dstYObj = args.GetCBObject(2);
	ICBObject* srcXObj = args.GetCBObject(3);
	ICBObject* srcYObj = args.GetCBObject(4);
	ICBObject* wObj = args.GetCBObject(5);
	ICBObject* hObj = args.GetCBObject(6);
	if (dstXObj == NULL || dstYObj == NULL || srcXObj == NULL || srcYObj == NULL || wObj == NULL || hObj == NULL)
	{
		return pCBrother->CreateCBObject(false);
	}

	int dstX = dstXObj->AnyTypeToInt();
	int dstY = dstYObj->AnyTypeToInt();
	int srcX = srcXObj->AnyTypeToInt();
	int srcY = srcYObj->AnyTypeToInt();
	int w = wObj->AnyTypeToInt();
	int h = hObj->AnyTypeToInt();

	if(!pCBrother->WriteLockCBClsObject(clsObj))
	{
		pException = pCBrother->CreateException("SyncException","multi thread access at object func! 'gd::Image' Object.");
		return NULL;
	}

	gdImagePtr src = (gdImagePtr)clsObj->GetUserParm();
	if (src == NULL)
	{
		pCBrother->WriteUnlockCBClsObject(clsObj);
		pException = pCBrother->CreateException("GDImageException","src is not gd::Image object.");
		return NULL;
	}

	gdImageCopy(im,src,dstX,dstY,srcX,srcY,w,h);
	pCBrother->WriteUnlockCBClsObject(clsObj);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageCopyMerge(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* srcObj = args.GetCBObject(0);
	if (srcObj == NULL || srcObj->Type() != CB_CLASS)
	{
		pException = pCBrother->CreateException("GDImageException","src is not gd::Image object.");
		return NULL;
	}

	IClassObject* clsObj = srcObj->ClassObjValue();
	if (strcmp(clsObj->GetCBClassName(),"gd::Image") != 0)
	{
		pException = pCBrother->CreateException("GDImageException","src is not gd::Image object.");
		return NULL;
	}

	ICBObject* dstXObj = args.GetCBObject(1);
	ICBObject* dstYObj = args.GetCBObject(2);
	ICBObject* srcXObj = args.GetCBObject(3);
	ICBObject* srcYObj = args.GetCBObject(4);
	ICBObject* wObj = args.GetCBObject(5);
	ICBObject* hObj = args.GetCBObject(6);
	ICBObject* pctObj = args.GetCBObject(7);
	if (dstXObj == NULL || dstYObj == NULL || srcXObj == NULL || srcYObj == NULL || wObj == NULL || hObj == NULL || pctObj == NULL)
	{
		return pCBrother->CreateCBObject(false);
	}

	int dstX = dstXObj->AnyTypeToInt();
	int dstY = dstYObj->AnyTypeToInt();
	int srcX = srcXObj->AnyTypeToInt();
	int srcY = srcYObj->AnyTypeToInt();
	int w = wObj->AnyTypeToInt();
	int h = hObj->AnyTypeToInt();
	int pct = pctObj->AnyTypeToInt();

	if(!pCBrother->WriteLockCBClsObject(clsObj))
	{
		pException = pCBrother->CreateException("SyncException","multi thread access at object func! 'gd::Image' Object.");
		return NULL;
	}

	gdImagePtr src = (gdImagePtr)clsObj->GetUserParm();
	if (src == NULL)
	{
		pCBrother->WriteUnlockCBClsObject(clsObj);
		pException = pCBrother->CreateException("GDImageException","src is not gd::Image object.");
		return NULL;
	}

	gdImageCopyMerge(im,src,dstX,dstY,srcX,srcY,w,h,pct);
	pCBrother->WriteUnlockCBClsObject(clsObj);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageClone(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* cloneImageObj = pCBrother->CreateCBClassObject("gd::Image");
	if (cloneImageObj == NULL)
	{
		return NULL;
	}

	gdImagePtr cloneImage = gdImageClone(im);
	if (cloneImage == NULL)
	{
		pCBrother->ReleaseCBObject(cloneImageObj);
		pException = pCBrother->CreateException("GDImageException","clone err.");
		return NULL;
	}

	cloneImageObj->ClassObjValue()->SetUserParm(cloneImage);	
	return cloneImageObj;
}

ICBObject* CBGdImage_gdImageScale(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* new_widthObj = args.GetCBObject(0);
	ICBObject* new_heightObj = args.GetCBObject(1);
	if (new_widthObj == NULL || new_heightObj == NULL)
	{
		return NULL;
	}

	int new_width = new_widthObj->AnyTypeToInt();
	int new_height = new_heightObj->AnyTypeToInt();

	ICBObject* cloneImageObj = pCBrother->CreateCBClassObject("gd::Image");
	if (cloneImageObj == NULL)
	{
		return NULL;
	}

	gdImagePtr cloneImage = gdImageScale(im,new_width,new_height);
	if (cloneImage == NULL)
	{
		pCBrother->ReleaseCBObject(cloneImageObj);
		pException = pCBrother->CreateException("GDImageException","scale err.");
		return NULL;
	}

	cloneImageObj->ClassObjValue()->SetUserParm(cloneImage);	
	return cloneImageObj;
}

ICBObject* CBGdImage_gdImageSetPixel(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* x1Obj = args.GetCBObject(0);
	ICBObject* y1Obj = args.GetCBObject(1);
	ICBObject* colorObj = args.GetCBObject(4);
	if (x1Obj == NULL || y1Obj == NULL || colorObj == NULL)
	{
		return pCBrother->CreateCBObject(false);
	}

	int x1 = x1Obj->AnyTypeToInt();
	int y1 = y1Obj->AnyTypeToInt();
	int color = colorObj->AnyTypeToInt();

	gdImageSetPixel(im,x1,y1,color);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageGetPixel(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* x1Obj = args.GetCBObject(0);
	ICBObject* y1Obj = args.GetCBObject(1);
	if (x1Obj == NULL || y1Obj == NULL)
	{
		return pCBrother->CreateCBObject(0);
	}

	int x1 = x1Obj->AnyTypeToInt();
	int y1 = y1Obj->AnyTypeToInt();
	return pCBrother->CreateCBObject(gdImageGetPixel(im,x1,y1));
}

ICBObject* CBGdImage_gdImageGetTrueColorPixel(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* x1Obj = args.GetCBObject(0);
	ICBObject* y1Obj = args.GetCBObject(1);
	if (x1Obj == NULL || y1Obj == NULL)
	{
		return pCBrother->CreateCBObject(0);
	}

	int x1 = x1Obj->AnyTypeToInt();
	int y1 = y1Obj->AnyTypeToInt();
	return pCBrother->CreateCBObject(gdImageGetTrueColorPixel(im,x1,y1));
}

ICBObject* CBGdImage_gdImageLine(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* x1Obj = args.GetCBObject(0);
	ICBObject* y1Obj = args.GetCBObject(1);
	ICBObject* x2Obj = args.GetCBObject(2);
	ICBObject* y2Obj = args.GetCBObject(3);
	ICBObject* colorObj = args.GetCBObject(4);
	if (x1Obj == NULL || y1Obj == NULL || x2Obj == NULL || y2Obj == NULL || colorObj == NULL)
	{
		return pCBrother->CreateCBObject(false);
	}

	int x1 = x1Obj->AnyTypeToInt();
	int y1 = y1Obj->AnyTypeToInt();
	int x2 = x2Obj->AnyTypeToInt();
	int y2 = y2Obj->AnyTypeToInt();
	int color = colorObj->AnyTypeToInt();

	gdImageLine(im,x1,y1,x2,y2,color);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageString(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* fObj = args.GetCBObject(0);
	ICBObject* xObj = args.GetCBObject(1);
	ICBObject* yObj = args.GetCBObject(2);
	ICBObject* sObj = args.GetCBObject(3);
	ICBObject* colorObj = args.GetCBObject(4);
	if (fObj == NULL || xObj == NULL || yObj == NULL || sObj == NULL || colorObj == NULL)
	{
		return pCBrother->CreateCBObject(false);
	}

	int f = fObj->AnyTypeToInt();
	gdFontPtr font = NULL;
	switch (f)
	{
	case 1:
		{
			font = gdFontGetTiny();
			break;
		}
	case 2:
		{
			font = gdFontGetSmall();
			break;
		}
	case 3:
		{
			font = gdFontGetMediumBold();
			break;
		}
	case 4:
		{
			font = gdFontGetLarge();
			break;
		}
	case 5:
		{
			font = gdFontGetGiant();
			break;
		}
	default:
		{
			return pCBrother->CreateCBObject(false);
		}
	}

	int x = xObj->AnyTypeToInt();
	int y = yObj->AnyTypeToInt();
	int color = colorObj->AnyTypeToInt();

	char buf[64] = {0};
	const char* s = sObj->AnyTypeToString(buf);

	gdImageString(im,font,x,y,(unsigned char*)s,color);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageStringUp(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* fObj = args.GetCBObject(0);
	ICBObject* xObj = args.GetCBObject(1);
	ICBObject* yObj = args.GetCBObject(2);
	ICBObject* sObj = args.GetCBObject(3);
	ICBObject* colorObj = args.GetCBObject(4);
	if (fObj == NULL || xObj == NULL || yObj == NULL || sObj == NULL || colorObj == NULL)
	{
		return pCBrother->CreateCBObject(false);
	}

	int f = fObj->AnyTypeToInt();
	gdFontPtr font = NULL;
	switch (f)
	{
	case 1:
		{
			font = gdFontGetTiny();
			break;
		}
	case 2:
		{
			font = gdFontGetSmall();
			break;
		}
	case 3:
		{
			font = gdFontGetMediumBold();
			break;
		}
	case 4:
		{
			font = gdFontGetLarge();
			break;
		}
	case 5:
		{
			font = gdFontGetGiant();
			break;
		}
	default:
		{
			return pCBrother->CreateCBObject(false);
		}
	}

	int x = xObj->AnyTypeToInt();
	int y = yObj->AnyTypeToInt();
	int color = colorObj->AnyTypeToInt();

	char buf[64] = {0};
	const char* s = sObj->AnyTypeToString(buf);

	gdImageStringUp(im,font,x,y,(unsigned char*)s,color);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageStringTTF(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* sizeObj = args.GetCBObject(0);
	ICBObject* angleObj = args.GetCBObject(1);
	ICBObject* xObj = args.GetCBObject(2);
	ICBObject* yObj = args.GetCBObject(3);
	ICBObject* colorObj = args.GetCBObject(4);
	ICBObject* fontlistObj = args.GetCBObject(5);
	ICBObject* textObj = args.GetCBObject(6);
	if (sizeObj == NULL || angleObj == NULL || xObj == NULL || yObj == NULL || colorObj == NULL || fontlistObj == NULL || textObj == NULL || 
		fontlistObj->Type() != CB_STRING)
	{
		return pCBrother->CreateCBObject(false);
	}

	float size = sizeObj->AnyTypeToFloat();
	float angle = angleObj->AnyTypeToFloat();
	int x = xObj->AnyTypeToInt();
	int y = yObj->AnyTypeToInt();
	int color = colorObj->AnyTypeToInt();
	const char* fontlist = fontlistObj->StringVal();
	char buf[64] = {0};
	const char* s = textObj->AnyTypeToString(buf);

	int brect[8] = {0};
	char* res = gdImageStringFT(im,brect,color,fontlist,size,angle,x,y,s);
	if (res != NULL)
	{
		pCBrother->CreateException("GDImageException",res);
		return NULL;
	}
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageJpeg(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* fileNameObj = args.GetCBObject(0);
	ICBObject* qualityObj = args.GetCBObject(1);
	if (fileNameObj == NULL || fileNameObj->Type() != CB_STRING)
	{
		return pCBrother->CreateCBObject(false);
	}

	int quality = 100;
	if (qualityObj != NULL)
	{
		quality = qualityObj->AnyTypeToInt();
	}

	const char* fileName = fileNameObj->StringVal();
	FILE* fp = fopen(fileName,"wb+");
	if (fp == NULL)
	{
		char buf[1024] = {0};
		sprintf(buf,"file open failed. %s",fileName);
		pException = pCBrother->CreateException("IOException",buf);
	}
	gdImageJpeg(im,fp,quality);
	fclose(fp);

	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageJpegPtr(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	int quality = 100;
	ICBObject* qualityObj = args.GetCBObject(0);
	if (qualityObj != NULL)
	{
		quality = qualityObj->AnyTypeToInt();
	}

	int size = 0;
	char* data = (char*)gdImageJpegPtr(im,&size,quality);
	if (data == NULL || size <= 0)
	{
		pException = pCBrother->CreateException("GDImageException","jpeg error.");
		return NULL;
	}

	ICBObject* lenObj = pCBrother->CreateCBObject(size + 1);
	ICBObject* byteArrayobj = pCBrother->CreateCBClassObject("ByteArray",1,lenObj);
	pCBrother->ReleaseCBObject(lenObj);

	IClassObject* clsobj = byteArrayobj->ClassObjValue();
	ICBByteBuffer* bytearray = (ICBByteBuffer*)clsobj->GetUserParm();
	bytearray->WriteBytes(data,size);
	free(data);

	return byteArrayobj;
}

ICBObject* CBGdImage_gdImagePng(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* fileNameObj = args.GetCBObject(0);
	if (fileNameObj == NULL || fileNameObj->Type() != CB_STRING)
	{
		return pCBrother->CreateCBObject(false);
	}

	const char* fileName = fileNameObj->StringVal();
	FILE* fp = fopen(fileName,"wb+");
	if (fp == NULL)
	{
		char buf[1024] = {0};
		sprintf(buf,"file open failed. %s",fileName);
		pException = pCBrother->CreateException("IOException",buf);
	}
	gdImagePng(im,fp);
	fclose(fp);

	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImagePngPtr(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	int size = 0;
	char* data = (char*)gdImagePngPtr(im,&size);
	if (data == NULL || size <= 0)
	{
		pException = pCBrother->CreateException("GDImageException","png error.");
		return NULL;
	}

	ICBObject* lenObj = pCBrother->CreateCBObject(size + 1);
	ICBObject* byteArrayobj = pCBrother->CreateCBClassObject("ByteArray",1,lenObj);
	pCBrother->ReleaseCBObject(lenObj);

	IClassObject* clsobj = byteArrayobj->ClassObjValue();
	ICBByteBuffer* bytearray = (ICBByteBuffer*)clsobj->GetUserParm();
	bytearray->WriteBytes(data,size);
	free(data);

	return byteArrayobj;
}

ICBObject* CBGdImage_gdImageGif(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* fileNameObj = args.GetCBObject(0);
	if (fileNameObj == NULL || fileNameObj->Type() != CB_STRING)
	{
		return pCBrother->CreateCBObject(false);
	}

	const char* fileName = fileNameObj->StringVal();
	FILE* fp = fopen(fileName,"wb+");
	if (fp == NULL)
	{
		char buf[1024] = {0};
		sprintf(buf,"file open failed. %s",fileName);
		pException = pCBrother->CreateException("IOException",buf);
	}
	gdImageGif(im,fp);
	fclose(fp);

	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageGifPtr(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	int size = 0;
	char* data = (char*)gdImageGifPtr(im,&size);
	if (data == NULL || size <= 0)
	{
		pException = pCBrother->CreateException("GDImageException","gif error.");
		return NULL;
	}

	ICBObject* lenObj = pCBrother->CreateCBObject(size + 1);
	ICBObject* byteArrayobj = pCBrother->CreateCBClassObject("ByteArray",1,lenObj);
	pCBrother->ReleaseCBObject(lenObj);

	IClassObject* clsobj = byteArrayobj->ClassObjValue();
	ICBByteBuffer* bytearray = (ICBByteBuffer*)clsobj->GetUserParm();
	bytearray->WriteBytes(data,size);
	free(data);

	return byteArrayobj;
}

ICBObject* CBGdImage_gdImageBmp(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* fileNameObj = args.GetCBObject(0);
	ICBObject* compressionObj = args.GetCBObject(1);
	if (fileNameObj == NULL || fileNameObj->Type() != CB_STRING)
	{
		return pCBrother->CreateCBObject(false);
	}

	int compression = 0;
	if (compressionObj != NULL)
	{
		compression = compressionObj->AnyTypeToInt();
	}

	const char* fileName = fileNameObj->StringVal();
	FILE* fp = fopen(fileName,"wb+");
	if (fp == NULL)
	{
		char buf[1024] = {0};
		sprintf(buf,"file open failed. %s",fileName);
		pException = pCBrother->CreateException("IOException",buf);
	}
	gdImageBmp(im,fp,compression);
	fclose(fp);

	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageBmpPtr(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* compressionObj = args.GetCBObject(0);
	int compression = 0;
	if (compressionObj != NULL)
	{
		compression = compressionObj->AnyTypeToInt();
	}

	int size = 0;
	char* data = (char*)gdImageBmpPtr(im,&size,compression);
	if (data == NULL || size <= 0)
	{
		pException = pCBrother->CreateException("GDImageException","bmp error.");
		return NULL;
	}

	ICBObject* lenObj = pCBrother->CreateCBObject(size + 1);
	ICBObject* byteArrayobj = pCBrother->CreateCBClassObject("ByteArray",1,lenObj);
	pCBrother->ReleaseCBObject(lenObj);

	IClassObject* clsobj = byteArrayobj->ClassObjValue();
	ICBByteBuffer* bytearray = (ICBByteBuffer*)clsobj->GetUserParm();
	bytearray->WriteBytes(data,size);
	free(data);

	return byteArrayobj;
}

ICBObject* CBGdImage_gdImageWebp(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* fileNameObj = args.GetCBObject(0);
	if (fileNameObj == NULL || fileNameObj->Type() != CB_STRING)
	{
		return pCBrother->CreateCBObject(false);
	}

	const char* fileName = fileNameObj->StringVal();
	FILE* fp = fopen(fileName,"wb+");
	if (fp == NULL)
	{
		char buf[1024] = {0};
		sprintf(buf,"file open failed. %s",fileName);
		pException = pCBrother->CreateException("IOException",buf);
	}
	gdImageWebp(im,fp);
	fclose(fp);

	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageWebpPtr(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	int size = 0;
	char* data = (char*)gdImageWebpPtr(im,&size);
	if (data == NULL || size <= 0)
	{
		pException = pCBrother->CreateException("GDImageException","webp error.");
		return NULL;
	}

	ICBObject* lenObj = pCBrother->CreateCBObject(size + 1);
	ICBObject* byteArrayobj = pCBrother->CreateCBClassObject("ByteArray",1,lenObj);
	pCBrother->ReleaseCBObject(lenObj);

	IClassObject* clsobj = byteArrayobj->ClassObjValue();
	ICBByteBuffer* bytearray = (ICBByteBuffer*)clsobj->GetUserParm();
	bytearray->WriteBytes(data,size);
	free(data);

	return byteArrayobj;
}

ICBObject* CBGdImage_gdImageCreateFromJpeg(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im != NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is already created.");
		return NULL;
	}

	ICBObject* fileNameObj = args.GetCBObject(0);
	if (fileNameObj->Type() == CB_STRING)
	{
		const char* fileName = fileNameObj->StringVal();
		FILE* fp = fopen(fileName,"rb");
		if (fp == NULL)
		{
			char buf[1024] = {0};
			sprintf(buf,"file open failed. %s",fileName);
			pException = pCBrother->CreateException("IOException",buf);
			return NULL;
		}
		im = gdImageCreateFromJpeg(fp);
		fclose(fp);
	}
	else if (fileNameObj->Type() == CB_CLASS)
	{
		ICBObject* lenObj = args.GetCBObject(1);
		IClassObject* clsObj = fileNameObj->ClassObjValue();
		if (strcmp(clsObj->GetCBClassName(),"ByteArray") != 0)
		{
			pException = pCBrother->CreateException("GDImageException","image data not is ByteArray.");
			return NULL;
		}

		if (!pCBrother->WriteLockCBClsObject(clsObj))
		{
			pCBrother->CreateException("SyncException","multi thread access at object func! 'ByteArray' Object!");
			return NULL;
		}

		ICBByteBuffer* byteArray = (ICBByteBuffer*)clsObj->GetUserParm();
		const char* data = byteArray->GetBuf() + byteArray->GetReadPos();
		int len = byteArray->GetWritePos() - byteArray->GetReadPos();
		if (lenObj != NULL)
		{
			len = lenObj->AnyTypeToInt();
		}
		im = gdImageCreateFromJpegPtr(len,(void*)data);
		pCBrother->WriteUnlockCBClsObject(clsObj);
	}
	else
	{
		pException = pCBrother->CreateException("GDImageException","image data error.");
		return NULL;
	}

	obj->SetUserParm(im);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageCreateFromPng(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im != NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is already created.");
		return NULL;
	}

	ICBObject* fileNameObj = args.GetCBObject(0);
	if (fileNameObj->Type() == CB_STRING)
	{
		const char* fileName = fileNameObj->StringVal();
		FILE* fp = fopen(fileName,"rb");
		if (fp == NULL)
		{
			char buf[1024] = {0};
			sprintf(buf,"file open failed. %s",fileName);
			pException = pCBrother->CreateException("IOException",buf);
			return NULL;
		}
		im = gdImageCreateFromPng(fp);
		fclose(fp);
	}
	else if (fileNameObj->Type() == CB_CLASS)
	{
		ICBObject* lenObj = args.GetCBObject(1);
		IClassObject* clsObj = fileNameObj->ClassObjValue();
		if (strcmp(clsObj->GetCBClassName(),"ByteArray") != 0)
		{
			pException = pCBrother->CreateException("GDImageException","image data not is ByteArray.");
			return NULL;
		}

		if (!pCBrother->WriteLockCBClsObject(clsObj))
		{
			pCBrother->CreateException("SyncException","multi thread access at object func! 'ByteArray' Object!");
			return NULL;
		}

		ICBByteBuffer* byteArray = (ICBByteBuffer*)clsObj->GetUserParm();
		const char* data = byteArray->GetBuf() + byteArray->GetReadPos();
		int len = byteArray->GetWritePos() - byteArray->GetReadPos();
		if (lenObj != NULL)
		{
			len = lenObj->AnyTypeToInt();
		}
		im = gdImageCreateFromPngPtr(len,(void*)data);
		pCBrother->WriteUnlockCBClsObject(clsObj);
	}
	else
	{
		pException = pCBrother->CreateException("GDImageException","image data error.");
		return NULL;
	}

	obj->SetUserParm(im);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageCreateFromGif(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im != NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is already created.");
		return NULL;
	}

	ICBObject* fileNameObj = args.GetCBObject(0);
	if (fileNameObj->Type() == CB_STRING)
	{
		const char* fileName = fileNameObj->StringVal();
		FILE* fp = fopen(fileName,"rb");
		if (fp == NULL)
		{
			char buf[1024] = {0};
			sprintf(buf,"file open failed. %s",fileName);
			pException = pCBrother->CreateException("IOException",buf);
			return NULL;
		}
		im = gdImageCreateFromGif(fp);
		fclose(fp);
	}
	else if (fileNameObj->Type() == CB_CLASS)
	{
		ICBObject* lenObj = args.GetCBObject(1);
		IClassObject* clsObj = fileNameObj->ClassObjValue();
		if (strcmp(clsObj->GetCBClassName(),"ByteArray") != 0)
		{
			pException = pCBrother->CreateException("GDImageException","image data not is ByteArray.");
			return NULL;
		}

		if (!pCBrother->WriteLockCBClsObject(clsObj))
		{
			pCBrother->CreateException("SyncException","multi thread access at object func! 'ByteArray' Object!");
			return NULL;
		}

		ICBByteBuffer* byteArray = (ICBByteBuffer*)clsObj->GetUserParm();
		const char* data = byteArray->GetBuf() + byteArray->GetReadPos();
		int len = byteArray->GetWritePos() - byteArray->GetReadPos();
		if (lenObj != NULL)
		{
			len = lenObj->AnyTypeToInt();
		}
		im = gdImageCreateFromGifPtr(len,(void*)data);
		pCBrother->WriteUnlockCBClsObject(clsObj);
	}
	else
	{
		pException = pCBrother->CreateException("GDImageException","image data error.");
		return NULL;
	}

	obj->SetUserParm(im);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageCreateFromBmp(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im != NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is already created.");
		return NULL;
	}

	ICBObject* fileNameObj = args.GetCBObject(0);
	if (fileNameObj->Type() == CB_STRING)
	{
		const char* fileName = fileNameObj->StringVal();
		FILE* fp = fopen(fileName,"rb");
		if (fp == NULL)
		{
			char buf[1024] = {0};
			sprintf(buf,"file open failed. %s",fileName);
			pException = pCBrother->CreateException("IOException",buf);
			return NULL;
		}
		im = gdImageCreateFromBmp(fp);
		fclose(fp);
	}
	else if (fileNameObj->Type() == CB_CLASS)
	{
		ICBObject* lenObj = args.GetCBObject(1);
		IClassObject* clsObj = fileNameObj->ClassObjValue();
		if (strcmp(clsObj->GetCBClassName(),"ByteArray") != 0)
		{
			pException = pCBrother->CreateException("GDImageException","image data not is ByteArray.");
			return NULL;
		}

		if (!pCBrother->WriteLockCBClsObject(clsObj))
		{
			pCBrother->CreateException("SyncException","multi thread access at object func! 'ByteArray' Object!");
			return NULL;
		}

		ICBByteBuffer* byteArray = (ICBByteBuffer*)clsObj->GetUserParm();
		const char* data = byteArray->GetBuf() + byteArray->GetReadPos();
		int len = byteArray->GetWritePos() - byteArray->GetReadPos();
		if (lenObj != NULL)
		{
			len = lenObj->AnyTypeToInt();
		}
		im = gdImageCreateFromBmpPtr(len,(void*)data);
		pCBrother->WriteUnlockCBClsObject(clsObj);
	}
	else
	{
		pException = pCBrother->CreateException("GDImageException","image data error.");
		return NULL;
	}

	obj->SetUserParm(im);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageCreateFromWebp(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im != NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is already created.");
		return NULL;
	}

	ICBObject* fileNameObj = args.GetCBObject(0);
	if (fileNameObj->Type() == CB_STRING)
	{
		const char* fileName = fileNameObj->StringVal();
		FILE* fp = fopen(fileName,"rb");
		if (fp == NULL)
		{
			char buf[1024] = {0};
			sprintf(buf,"file open failed. %s",fileName);
			pException = pCBrother->CreateException("IOException",buf);
			return NULL;
		}
		im = gdImageCreateFromWebp(fp);
		fclose(fp);
	}
	else if (fileNameObj->Type() == CB_CLASS)
	{
		ICBObject* lenObj = args.GetCBObject(1);
		IClassObject* clsObj = fileNameObj->ClassObjValue();
		if (strcmp(clsObj->GetCBClassName(),"ByteArray") != 0)
		{
			pException = pCBrother->CreateException("GDImageException","image data not is ByteArray.");
			return NULL;
		}

		if (!pCBrother->WriteLockCBClsObject(clsObj))
		{
			pCBrother->CreateException("SyncException","multi thread access at object func! 'ByteArray' Object!");
			return NULL;
		}

		ICBByteBuffer* byteArray = (ICBByteBuffer*)clsObj->GetUserParm();
		const char* data = byteArray->GetBuf() + byteArray->GetReadPos();
		int len = byteArray->GetWritePos() - byteArray->GetReadPos();
		if (lenObj != NULL)
		{
			len = lenObj->AnyTypeToInt();
		}
		im = gdImageCreateFromWebpPtr(len,(void*)data);
		pCBrother->WriteUnlockCBClsObject(clsObj);
	}
	else
	{
		pException = pCBrother->CreateException("GDImageException","image data error.");
		return NULL;
	}

	obj->SetUserParm(im);
	return pCBrother->CreateCBObject(true);
}

ICBObject* CBGdImage_gdImageSX(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	return pCBrother->CreateCBObject(gdImageSX(im));
}

ICBObject* CBGdImage_gdImageSY(ICBrother* pCBrother,ICBObjectList &args,IClassObject* obj,ICBException* &pException)
{
	gdImagePtr im = (gdImagePtr)obj->GetUserParm();
	if (im == NULL)
	{
		pException = pCBrother->CreateException("GDImageException","image is not created.");
		return NULL;
	}

	return pCBrother->CreateCBObject(gdImageSY(im));
}

bool Init(ICBrother* pCBrother)
{
	//regiest your function and class
	pCBrother->RegisterCBClass("Image",CBGdImage_Init,CBGdImage_Release,"gd");
	pCBrother->RegisterCBClassFunc("gd::Image","create",CBGdImage_gdImageCreate,true);
	pCBrother->RegisterCBClassFunc("gd::Image","createTrueColor",CBGdImage_gdImageCreateTrueColor,true);
	pCBrother->RegisterCBClassFunc("gd::Image","createFromJpeg",CBGdImage_gdImageCreateFromJpeg,true);
	pCBrother->RegisterCBClassFunc("gd::Image","createFromPng",CBGdImage_gdImageCreateFromPng,true);
	pCBrother->RegisterCBClassFunc("gd::Image","createFromGif",CBGdImage_gdImageCreateFromGif,true);
	pCBrother->RegisterCBClassFunc("gd::Image","createFromBmp",CBGdImage_gdImageCreateFromBmp,true);
	pCBrother->RegisterCBClassFunc("gd::Image","createFromWebp",CBGdImage_gdImageCreateFromWebp,true);
	pCBrother->RegisterCBClassFunc("gd::Image","colorAllocate",CBGdImage_gdImageColorAllocate,true);
	pCBrother->RegisterCBClassFunc("gd::Image","colorAllocateAlpha",CBGdImage_gdImageColorAllocateAlpha,true);
	pCBrother->RegisterCBClassFunc("gd::Image","arc",CBGdImage_gdImageArc,true);
	pCBrother->RegisterCBClassFunc("gd::Image","filledArc",CBGdImage_gdImageFilledArc,true);
	pCBrother->RegisterCBClassFunc("gd::Image","ellipse",CBGdImage_gdImageEllipse,true);
	pCBrother->RegisterCBClassFunc("gd::Image","filledEllipse",CBGdImage_gdImageFilledEllipse,true);
	pCBrother->RegisterCBClassFunc("gd::Image","rectangle",CBGdImage_gdImageRectangle,true);
	pCBrother->RegisterCBClassFunc("gd::Image","filledRectangle",CBGdImage_gdImageFilledRectangle,true);
	pCBrother->RegisterCBClassFunc("gd::Image","fill",CBGdImage_gdImageFill,true);
	pCBrother->RegisterCBClassFunc("gd::Image","filledToBorder",CBGdImage_gdImageFillToBorder,true);
	pCBrother->RegisterCBClassFunc("gd::Image","copy",CBGdImage_gdImageCopy,true);
	pCBrother->RegisterCBClassFunc("gd::Image","copyMerge",CBGdImage_gdImageCopyMerge,true);
	pCBrother->RegisterCBClassFunc("gd::Image","clone",CBGdImage_gdImageClone,true);
	pCBrother->RegisterCBClassFunc("gd::Image","scale",CBGdImage_gdImageScale,true);	
	pCBrother->RegisterCBClassFunc("gd::Image","setPixel",CBGdImage_gdImageSetPixel,true);
	pCBrother->RegisterCBClassFunc("gd::Image","getPixel",CBGdImage_gdImageGetPixel,true);
	pCBrother->RegisterCBClassFunc("gd::Image","getTrueColorPixel",CBGdImage_gdImageGetTrueColorPixel,true);
	pCBrother->RegisterCBClassFunc("gd::Image","line",CBGdImage_gdImageLine,true);
	pCBrother->RegisterCBClassFunc("gd::Image","string",CBGdImage_gdImageString,true);
	pCBrother->RegisterCBClassFunc("gd::Image","stringUp",CBGdImage_gdImageStringUp,true);
	pCBrother->RegisterCBClassFunc("gd::Image","stringTTF",CBGdImage_gdImageStringTTF,true);
	pCBrother->RegisterCBClassFunc("gd::Image","saveJpegFile",CBGdImage_gdImageJpeg,true);
	pCBrother->RegisterCBClassFunc("gd::Image","saveJpegBytes",CBGdImage_gdImageJpegPtr,true);
	pCBrother->RegisterCBClassFunc("gd::Image","savePngFile",CBGdImage_gdImagePng,true);
	pCBrother->RegisterCBClassFunc("gd::Image","savePngBytes",CBGdImage_gdImagePngPtr,true);
	pCBrother->RegisterCBClassFunc("gd::Image","saveGifFile",CBGdImage_gdImageGif,true);
	pCBrother->RegisterCBClassFunc("gd::Image","saveGifBytes",CBGdImage_gdImageGifPtr,true);
	pCBrother->RegisterCBClassFunc("gd::Image","saveBmpFile",CBGdImage_gdImageBmp,true);
	pCBrother->RegisterCBClassFunc("gd::Image","saveBmpBytes",CBGdImage_gdImageBmpPtr,true);
	pCBrother->RegisterCBClassFunc("gd::Image","saveWebpFile",CBGdImage_gdImageWebp,true);
	pCBrother->RegisterCBClassFunc("gd::Image","saveWebpBytes",CBGdImage_gdImageWebpPtr,true);
	pCBrother->RegisterCBClassFunc("gd::Image","sx",CBGdImage_gdImageSX,true);
	pCBrother->RegisterCBClassFunc("gd::Image","sy",CBGdImage_gdImageSY,true);

	return true;

}
CREATE_CBROTHER_MODULE(Init)
