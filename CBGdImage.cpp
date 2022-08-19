#include "ICBModule.h"

#include <string.h>
#include <stdio.h>

#include <gd.h>
#include <gdfontg.h>
#include <gdfontl.h>
#include <gdfontt.h>
#include <gdfonts.h>
#include <gdfontmb.h>

ICBObject* CBGdImage_Init(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	return NULL;
}

void CBGdImage_Release(ICBrother* pCBrother,IClassObject* obj,int releaseType)
{
	if (releaseType != CB_RELEASE)
	{
		return;
	}

	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im != NULL)
	{
		gdImageDestroy(im);
	}
}

ICBObject* CBGdImage_gdImageCreate(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im != NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is already created.");
		return NULL;
	}

	ICBObject* sxObj = ICBObjectList_GetCBObject(args,0);
	ICBObject* syObj = ICBObjectList_GetCBObject(args,1);
	if (sxObj == NULL || syObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int sx = ICBObject_AnyTypeToInt(sxObj);
	int sy = ICBObject_AnyTypeToInt(syObj);
	im = gdImageCreate(sx,sy);
	IClassObject_SetUserParm(obj,im);
	return ICBrother_CreateCBObjectBool(pCBrother,im != NULL);
}

ICBObject* CBGdImage_gdImageCreateTrueColor(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im != NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is already created.");
		return NULL;
	}

	ICBObject* sxObj = ICBObjectList_GetCBObject(args,0);
	ICBObject* syObj = ICBObjectList_GetCBObject(args,1);
	if (sxObj == NULL || syObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int sx = ICBObject_AnyTypeToInt(sxObj);
	int sy = ICBObject_AnyTypeToInt(syObj);
	im = gdImageCreateTrueColor(sx,sy);
	IClassObject_SetUserParm(obj,im);
	return ICBrother_CreateCBObjectBool(pCBrother,im != NULL);
}

ICBObject* CBGdImage_gdImageColorAllocate(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* rObj = ICBObjectList_GetCBObject(args,0);
	ICBObject* gObj = ICBObjectList_GetCBObject(args,1);
	ICBObject* bObj = ICBObjectList_GetCBObject(args,2);
	if (rObj == NULL || gObj == NULL || bObj == NULL)
	{
		return ICBrother_CreateCBObjectInt(pCBrother,-1);
	}

	int r = ICBObject_AnyTypeToInt(rObj);
	int g = ICBObject_AnyTypeToInt(gObj);
	int b = ICBObject_AnyTypeToInt(bObj);
	int ci = gdImageColorAllocate(im,r,g,b);
	return ICBrother_CreateCBObjectInt(pCBrother,ci);
}

ICBObject* CBGdImage_gdImageColorAllocateAlpha(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* rObj = ICBObjectList_GetCBObject(args,0);
	ICBObject* gObj = ICBObjectList_GetCBObject(args,1);
	ICBObject* bObj = ICBObjectList_GetCBObject(args,2);
	ICBObject* aObj = ICBObjectList_GetCBObject(args,3);
	if (rObj == NULL || gObj == NULL || bObj == NULL || aObj == NULL)
	{
		return ICBrother_CreateCBObjectInt(pCBrother,-1);
	}

	int r = ICBObject_AnyTypeToInt(rObj);
	int g = ICBObject_AnyTypeToInt(gObj);
	int b = ICBObject_AnyTypeToInt(bObj);
	int a = ICBObject_AnyTypeToInt(aObj);
	int ci = gdImageColorAllocateAlpha(im,r,g,b,a);
	return ICBrother_CreateCBObjectInt(pCBrother,ci);
}

ICBObject* CBGdImage_gdImageArc(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* cxObj = ICBObjectList_GetCBObject(args,0);
	ICBObject* cyObj = ICBObjectList_GetCBObject(args,1);
	ICBObject* wObj = ICBObjectList_GetCBObject(args,2);
	ICBObject* hObj = ICBObjectList_GetCBObject(args,3);
	ICBObject* sObj = ICBObjectList_GetCBObject(args,4);
	ICBObject* eObj = ICBObjectList_GetCBObject(args,5);
	ICBObject* colorObj = ICBObjectList_GetCBObject(args,6);
	if (cxObj == NULL || cyObj == NULL || wObj == NULL || hObj == NULL || sObj == NULL || eObj == NULL || colorObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int cx = ICBObject_AnyTypeToInt(cxObj);
	int cy = ICBObject_AnyTypeToInt(cyObj);
	int w = ICBObject_AnyTypeToInt(wObj);
	int h = ICBObject_AnyTypeToInt(hObj);
	int s = ICBObject_AnyTypeToInt(sObj);
	int e = ICBObject_AnyTypeToInt(eObj);
	int color = ICBObject_AnyTypeToInt(colorObj);

	gdImageArc(im,cx,cy,w,h,s,e,color);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageFilledArc(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* cxObj = ICBObjectList_GetCBObject(args,0);
	ICBObject* cyObj = ICBObjectList_GetCBObject(args,1);
	ICBObject* wObj = ICBObjectList_GetCBObject(args,2);
	ICBObject* hObj = ICBObjectList_GetCBObject(args,3);
	ICBObject* sObj = ICBObjectList_GetCBObject(args,4);
	ICBObject* eObj = ICBObjectList_GetCBObject(args,5);
	ICBObject* colorObj = ICBObjectList_GetCBObject(args,6);
	ICBObject* styleObj = ICBObjectList_GetCBObject(args,7);
	if (cxObj == NULL || cyObj == NULL || wObj == NULL || hObj == NULL || sObj == NULL || eObj == NULL || colorObj == NULL || styleObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int cx = ICBObject_AnyTypeToInt(cxObj);
	int cy = ICBObject_AnyTypeToInt(cyObj);
	int w = ICBObject_AnyTypeToInt(wObj);
	int h = ICBObject_AnyTypeToInt(hObj);
	int s = ICBObject_AnyTypeToInt(sObj);
	int e = ICBObject_AnyTypeToInt(eObj);
	int color = ICBObject_AnyTypeToInt(colorObj);
	int style = ICBObject_AnyTypeToInt(styleObj);

	gdImageFilledArc(im,cx,cy,w,h,s,e,color,style);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageEllipse(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* cxObj = ICBObjectList_GetCBObject(args,0);
	ICBObject* cyObj = ICBObjectList_GetCBObject(args,1);
	ICBObject* wObj = ICBObjectList_GetCBObject(args,2);
	ICBObject* hObj = ICBObjectList_GetCBObject(args,3);
	ICBObject* colorObj = ICBObjectList_GetCBObject(args,4);
	if (cxObj == NULL || cyObj == NULL || wObj == NULL || hObj == NULL || colorObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int cx = ICBObject_AnyTypeToInt(cxObj);
	int cy = ICBObject_AnyTypeToInt(cyObj);
	int w = ICBObject_AnyTypeToInt(wObj);
	int h = ICBObject_AnyTypeToInt(hObj);
	int color = ICBObject_AnyTypeToInt(colorObj);

	gdImageEllipse(im,cx,cy,w,h,color);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageFilledEllipse(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* cxObj = ICBObjectList_GetCBObject(args,0);
	ICBObject* cyObj = ICBObjectList_GetCBObject(args,1);
	ICBObject* wObj = ICBObjectList_GetCBObject(args,2);
	ICBObject* hObj = ICBObjectList_GetCBObject(args,3);
	ICBObject* colorObj = ICBObjectList_GetCBObject(args,4);
	if (cxObj == NULL || cyObj == NULL || wObj == NULL || hObj == NULL || colorObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int cx = ICBObject_AnyTypeToInt(cxObj);
	int cy = ICBObject_AnyTypeToInt(cyObj);
	int w = ICBObject_AnyTypeToInt(wObj);
	int h = ICBObject_AnyTypeToInt(hObj);
	int color = ICBObject_AnyTypeToInt(colorObj);

	gdImageFilledEllipse(im,cx,cy,w,h,color);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageRectangle(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* x1Obj = ICBObjectList_GetCBObject(args,0);
	ICBObject* y1Obj = ICBObjectList_GetCBObject(args,1);
	ICBObject* x2Obj = ICBObjectList_GetCBObject(args,2);
	ICBObject* y2Obj = ICBObjectList_GetCBObject(args,3);
	ICBObject* colorObj = ICBObjectList_GetCBObject(args,4);
	if (x1Obj == NULL || y1Obj == NULL || x2Obj == NULL || y2Obj == NULL || colorObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int x1 = ICBObject_AnyTypeToInt(x1Obj);
	int y1 = ICBObject_AnyTypeToInt(y1Obj);
	int x2 = ICBObject_AnyTypeToInt(x2Obj);
	int y2 = ICBObject_AnyTypeToInt(y2Obj);
	int color = ICBObject_AnyTypeToInt(colorObj);

	gdImageRectangle(im,x1,y1,x2,y2,color);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageFilledRectangle(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* x1Obj = ICBObjectList_GetCBObject(args,0);
	ICBObject* y1Obj = ICBObjectList_GetCBObject(args,1);
	ICBObject* x2Obj = ICBObjectList_GetCBObject(args,2);
	ICBObject* y2Obj = ICBObjectList_GetCBObject(args,3);
	ICBObject* colorObj = ICBObjectList_GetCBObject(args,4);
	if (x1Obj == NULL || y1Obj == NULL || x2Obj == NULL || y2Obj == NULL || colorObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int x1 = ICBObject_AnyTypeToInt(x1Obj);
	int y1 = ICBObject_AnyTypeToInt(y1Obj);
	int x2 = ICBObject_AnyTypeToInt(x2Obj);
	int y2 = ICBObject_AnyTypeToInt(y2Obj);
	int color = ICBObject_AnyTypeToInt(colorObj);

	gdImageFilledRectangle(im,x1,y1,x2,y2,color);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageFillToBorder(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* x1Obj = ICBObjectList_GetCBObject(args,0);
	ICBObject* y1Obj = ICBObjectList_GetCBObject(args,1);
	ICBObject* borderObj = ICBObjectList_GetCBObject(args,2);
	ICBObject* colorObj = ICBObjectList_GetCBObject(args,3);
	if (x1Obj == NULL || y1Obj == NULL || borderObj == NULL || colorObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int x1 = ICBObject_AnyTypeToInt(x1Obj);
	int y1 = ICBObject_AnyTypeToInt(y1Obj);
	int border = ICBObject_AnyTypeToInt(borderObj);
	int color = ICBObject_AnyTypeToInt(colorObj);

	gdImageFillToBorder(im,x1,y1,border,color);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageFill(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* x1Obj = ICBObjectList_GetCBObject(args,0);
	ICBObject* y1Obj = ICBObjectList_GetCBObject(args,1);
	ICBObject* colorObj = ICBObjectList_GetCBObject(args,2);
	if (x1Obj == NULL || y1Obj == NULL || colorObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int x1 = ICBObject_AnyTypeToInt(x1Obj);
	int y1 = ICBObject_AnyTypeToInt(y1Obj);
	int color = ICBObject_AnyTypeToInt(colorObj);

	gdImageFill(im,x1,y1,color);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageCopy(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* srcObj = ICBObjectList_GetCBObject(args,0);
	if (srcObj == NULL || ICBObject_Type(srcObj) != CB_CLASS)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","src is not gd::Image object.");
		return NULL;
	}

	IClassObject* clsObj = ICBObject_ClassObjValue(srcObj);
	if (strcmp(IClassObject_GetCBClassName(clsObj),"gd::Image") != 0)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","src is not gd::Image object.");
		return NULL;
	}

	ICBObject* dstXObj = ICBObjectList_GetCBObject(args,1);
	ICBObject* dstYObj = ICBObjectList_GetCBObject(args,2);
	ICBObject* srcXObj = ICBObjectList_GetCBObject(args,3);
	ICBObject* srcYObj = ICBObjectList_GetCBObject(args,4);
	ICBObject* wObj = ICBObjectList_GetCBObject(args,5);
	ICBObject* hObj = ICBObjectList_GetCBObject(args,6);
	if (dstXObj == NULL || dstYObj == NULL || srcXObj == NULL || srcYObj == NULL || wObj == NULL || hObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int dstX = ICBObject_AnyTypeToInt(dstXObj);
	int dstY = ICBObject_AnyTypeToInt(dstYObj);
	int srcX = ICBObject_AnyTypeToInt(srcXObj);
	int srcY = ICBObject_AnyTypeToInt(srcYObj);
	int w = ICBObject_AnyTypeToInt(wObj);
	int h = ICBObject_AnyTypeToInt(hObj);

	if(!ICBrother_WriteLockCBClsObject(pCBrother,clsObj))
	{
		*pException = ICBrother_CreateException(pCBrother,"SyncException","multi thread access at object func! 'gd::Image' Object.");
		return NULL;
	}

	gdImagePtr src = (gdImagePtr)IClassObject_GetUserParm(clsObj);
	if (src == NULL)
	{
		ICBrother_WriteUnlockCBClsObject(pCBrother,clsObj);
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","src is not gd::Image object.");
		return NULL;
	}

	gdImageCopy(im,src,dstX,dstY,srcX,srcY,w,h);
	ICBrother_WriteUnlockCBClsObject(pCBrother,clsObj);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageCopyMerge(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* srcObj = ICBObjectList_GetCBObject(args,0);
	if (srcObj == NULL || ICBObject_Type(srcObj) != CB_CLASS)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","src is not gd::Image object.");
		return NULL;
	}

	IClassObject* clsObj = ICBObject_ClassObjValue(srcObj);
	if (strcmp(IClassObject_GetCBClassName(clsObj),"gd::Image") != 0)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","src is not gd::Image object.");
		return NULL;
	}

	ICBObject* dstXObj = ICBObjectList_GetCBObject(args,1);
	ICBObject* dstYObj = ICBObjectList_GetCBObject(args,2);
	ICBObject* srcXObj = ICBObjectList_GetCBObject(args,3);
	ICBObject* srcYObj = ICBObjectList_GetCBObject(args,4);
	ICBObject* wObj = ICBObjectList_GetCBObject(args,5);
	ICBObject* hObj = ICBObjectList_GetCBObject(args,6);
	ICBObject* pctObj = ICBObjectList_GetCBObject(args,7);
	if (dstXObj == NULL || dstYObj == NULL || srcXObj == NULL || srcYObj == NULL || wObj == NULL || hObj == NULL || pctObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int dstX = ICBObject_AnyTypeToInt(dstXObj);
	int dstY = ICBObject_AnyTypeToInt(dstYObj);
	int srcX = ICBObject_AnyTypeToInt(srcXObj);
	int srcY = ICBObject_AnyTypeToInt(srcYObj);
	int w = ICBObject_AnyTypeToInt(wObj);
	int h = ICBObject_AnyTypeToInt(hObj);
	int pct = ICBObject_AnyTypeToInt(pctObj);

	if(!ICBrother_WriteLockCBClsObject(pCBrother,clsObj))
	{
		*pException = ICBrother_CreateException(pCBrother,"SyncException","multi thread access at object func! 'gd::Image' Object.");
		return NULL;
	}

	gdImagePtr src = (gdImagePtr)IClassObject_GetUserParm(clsObj);
	if (src == NULL)
	{
		ICBrother_WriteUnlockCBClsObject(pCBrother,clsObj);
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","src is not gd::Image object.");
		return NULL;
	}

	gdImageCopyMerge(im,src,dstX,dstY,srcX,srcY,w,h,pct);
	ICBrother_WriteUnlockCBClsObject(pCBrother,clsObj);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageCopyResized(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* srcObj = ICBObjectList_GetCBObject(args,0);
	if (srcObj == NULL || ICBObject_Type(srcObj) != CB_CLASS)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","src is not gd::Image object.");
		return NULL;
	}

	IClassObject* clsObj = ICBObject_ClassObjValue(srcObj);
	if (strcmp(IClassObject_GetCBClassName(clsObj),"gd::Image") != 0)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","src is not gd::Image object.");
		return NULL;
	}

	ICBObject* dstXObj = ICBObjectList_GetCBObject(args,1);
	ICBObject* dstYObj = ICBObjectList_GetCBObject(args,2);
	ICBObject* srcXObj = ICBObjectList_GetCBObject(args,3);
	ICBObject* srcYObj = ICBObjectList_GetCBObject(args,4);
	ICBObject* dstWObj = ICBObjectList_GetCBObject(args,5);
	ICBObject* dstHObj = ICBObjectList_GetCBObject(args,6);
	ICBObject* srcWObj = ICBObjectList_GetCBObject(args,7);
	ICBObject* srcHObj = ICBObjectList_GetCBObject(args,8);
	if (dstXObj == NULL || dstYObj == NULL || srcXObj == NULL || srcYObj == NULL || dstWObj == NULL || dstHObj == NULL || srcWObj == NULL || srcHObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int dstX = ICBObject_AnyTypeToInt(dstXObj);
	int dstY = ICBObject_AnyTypeToInt(dstYObj);
	int srcX = ICBObject_AnyTypeToInt(srcXObj);
	int srcY = ICBObject_AnyTypeToInt(srcYObj);
	int dstW = ICBObject_AnyTypeToInt(dstWObj);
	int dstH = ICBObject_AnyTypeToInt(dstHObj);
	int srcW = ICBObject_AnyTypeToInt(srcWObj);
	int srcH = ICBObject_AnyTypeToInt(srcHObj);

	if(!ICBrother_WriteLockCBClsObject(pCBrother,clsObj))
	{
		*pException = ICBrother_CreateException(pCBrother,"SyncException","multi thread access at object func! 'gd::Image' Object.");
		return NULL;
	}

	gdImagePtr src = (gdImagePtr)IClassObject_GetUserParm(clsObj);
	if (src == NULL)
	{
		ICBrother_WriteUnlockCBClsObject(pCBrother,clsObj);
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","src is not gd::Image object.");
		return NULL;
	}

	gdImageCopyResized(im,src,dstX,dstY,srcX,srcY,dstW,dstH,srcW,srcH);
	ICBrother_WriteUnlockCBClsObject(pCBrother,clsObj);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageClone(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* cloneImageObj = ICBrother_CreateCBClassObject(pCBrother,"gd::Image",NULL,0);
	if (cloneImageObj == NULL)
	{
		return NULL;
	}

	gdImagePtr cloneImage = gdImageClone(im);
	if (cloneImage == NULL)
	{
		ICBrother_ReleaseCBObject(pCBrother,cloneImageObj);
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","clone err.");
		return NULL;
	}

	IClassObject_SetUserParm(ICBObject_ClassObjValue(cloneImageObj),cloneImage);	
	return cloneImageObj;
}

ICBObject* CBGdImage_gdImageScale(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* new_widthObj = ICBObjectList_GetCBObject(args,0);
	ICBObject* new_heightObj = ICBObjectList_GetCBObject(args,1);
	if (new_widthObj == NULL || new_heightObj == NULL)
	{
		return NULL;
	}

	int new_width = ICBObject_AnyTypeToInt(new_widthObj);
	int new_height = ICBObject_AnyTypeToInt(new_heightObj);

	ICBObject* cloneImageObj = ICBrother_CreateCBClassObject(pCBrother,"gd::Image",NULL,0);
	if (cloneImageObj == NULL)
	{
		return NULL;
	}

	gdImagePtr cloneImage = gdImageScale(im,new_width,new_height);
	if (cloneImage == NULL)
	{
		ICBrother_ReleaseCBObject(pCBrother,cloneImageObj);
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","scale err.");
		return NULL;
	}

	IClassObject_SetUserParm(ICBObject_ClassObjValue(cloneImageObj),cloneImage);	
	return cloneImageObj;
}

ICBObject* CBGdImage_gdImageSetPixel(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* x1Obj = ICBObjectList_GetCBObject(args,0);
	ICBObject* y1Obj = ICBObjectList_GetCBObject(args,1);
	ICBObject* colorObj = ICBObjectList_GetCBObject(args,2);
	if (x1Obj == NULL || y1Obj == NULL || colorObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int x1 = ICBObject_AnyTypeToInt(x1Obj);
	int y1 = ICBObject_AnyTypeToInt(y1Obj);
	int color = ICBObject_AnyTypeToInt(colorObj);

	gdImageSetPixel(im,x1,y1,color);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageGetPixel(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* x1Obj = ICBObjectList_GetCBObject(args,0);
	ICBObject* y1Obj = ICBObjectList_GetCBObject(args,1);
	if (x1Obj == NULL || y1Obj == NULL)
	{
		return ICBrother_CreateCBObjectInt(pCBrother,0);
	}

	int x1 = ICBObject_AnyTypeToInt(x1Obj);
	int y1 = ICBObject_AnyTypeToInt(y1Obj);
	return ICBrother_CreateCBObjectInt(pCBrother,gdImageGetPixel(im,x1,y1));
}

ICBObject* CBGdImage_gdImageGetTrueColorPixel(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* x1Obj = ICBObjectList_GetCBObject(args,0);
	ICBObject* y1Obj = ICBObjectList_GetCBObject(args,1);
	if (x1Obj == NULL || y1Obj == NULL)
	{
		return ICBrother_CreateCBObjectInt(pCBrother,0);
	}

	int x1 = ICBObject_AnyTypeToInt(x1Obj);
	int y1 = ICBObject_AnyTypeToInt(y1Obj);
	return ICBrother_CreateCBObjectInt(pCBrother,gdImageGetTrueColorPixel(im,x1,y1));
}

ICBObject* CBGdImage_gdImageLine(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* x1Obj = ICBObjectList_GetCBObject(args,0);
	ICBObject* y1Obj = ICBObjectList_GetCBObject(args,1);
	ICBObject* x2Obj = ICBObjectList_GetCBObject(args,2);
	ICBObject* y2Obj = ICBObjectList_GetCBObject(args,3);
	ICBObject* colorObj = ICBObjectList_GetCBObject(args,4);
	if (x1Obj == NULL || y1Obj == NULL || x2Obj == NULL || y2Obj == NULL || colorObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int x1 = ICBObject_AnyTypeToInt(x1Obj);
	int y1 = ICBObject_AnyTypeToInt(y1Obj);
	int x2 = ICBObject_AnyTypeToInt(x2Obj);
	int y2 = ICBObject_AnyTypeToInt(y2Obj);
	int color = ICBObject_AnyTypeToInt(colorObj);

	gdImageLine(im,x1,y1,x2,y2,color);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageString(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* fObj = ICBObjectList_GetCBObject(args,0);
	ICBObject* xObj = ICBObjectList_GetCBObject(args,1);
	ICBObject* yObj = ICBObjectList_GetCBObject(args,2);
	ICBObject* sObj = ICBObjectList_GetCBObject(args,3);
	ICBObject* colorObj = ICBObjectList_GetCBObject(args,4);
	if (fObj == NULL || xObj == NULL || yObj == NULL || sObj == NULL || colorObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int f = ICBObject_AnyTypeToInt(fObj);
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
			return ICBrother_CreateCBObjectBool(pCBrother,false);
		}
	}

	int x = ICBObject_AnyTypeToInt(xObj);
	int y = ICBObject_AnyTypeToInt(yObj);
	int color = ICBObject_AnyTypeToInt(colorObj);

	char buf[64] = {0};
	const char* s = ICBObject_AnyTypeToString(sObj,buf);

	gdImageString(im,font,x,y,(unsigned char*)s,color);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageStringUp(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* fObj = ICBObjectList_GetCBObject(args,0);
	ICBObject* xObj = ICBObjectList_GetCBObject(args,1);
	ICBObject* yObj = ICBObjectList_GetCBObject(args,2);
	ICBObject* sObj = ICBObjectList_GetCBObject(args,3);
	ICBObject* colorObj = ICBObjectList_GetCBObject(args,4);
	if (fObj == NULL || xObj == NULL || yObj == NULL || sObj == NULL || colorObj == NULL)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int f = ICBObject_AnyTypeToInt(fObj);
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
			return ICBrother_CreateCBObjectBool(pCBrother,false);
		}
	}

	int x = ICBObject_AnyTypeToInt(xObj);
	int y = ICBObject_AnyTypeToInt(yObj);
	int color = ICBObject_AnyTypeToInt(colorObj);

	char buf[64] = {0};
	const char* s = ICBObject_AnyTypeToString(sObj,buf);

	gdImageStringUp(im,font,x,y,(unsigned char*)s,color);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageStringTTF(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* sizeObj = ICBObjectList_GetCBObject(args,0);
	ICBObject* angleObj = ICBObjectList_GetCBObject(args,1);
	ICBObject* xObj = ICBObjectList_GetCBObject(args,2);
	ICBObject* yObj = ICBObjectList_GetCBObject(args,3);
	ICBObject* colorObj = ICBObjectList_GetCBObject(args,4);
	ICBObject* fontlistObj = ICBObjectList_GetCBObject(args,5);
	ICBObject* textObj = ICBObjectList_GetCBObject(args,6);
	if (sizeObj == NULL || angleObj == NULL || xObj == NULL || yObj == NULL || colorObj == NULL || fontlistObj == NULL || textObj == NULL || 
		ICBObject_Type(fontlistObj) != CB_STRING)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	float size = ICBObject_AnyTypeToFloat(sizeObj);
	float angle = ICBObject_AnyTypeToFloat(angleObj);
	int x = ICBObject_AnyTypeToInt(xObj);
	int y = ICBObject_AnyTypeToInt(yObj);
	int color = ICBObject_AnyTypeToInt(colorObj);
	const char* fontlist = ICBObject_StringVal(fontlistObj);
	char buf[64] = {0};
	const char* s = ICBObject_AnyTypeToString(textObj,buf);

	int brect[8] = {0};
	char* res = gdImageStringFT(im,brect,color,fontlist,size,angle,x,y,s);
	if (res != NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException",res);
		return NULL;
	}
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageJpeg(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* fileNameObj = ICBObjectList_GetCBObject(args,0);
	ICBObject* qualityObj = ICBObjectList_GetCBObject(args,1);
	if (fileNameObj == NULL || ICBObject_Type(fileNameObj) != CB_STRING)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int quality = 100;
	if (qualityObj != NULL)
	{
		quality = ICBObject_AnyTypeToInt(qualityObj);
	}

	const char* fileName = ICBObject_StringVal(fileNameObj);
	FILE* fp = fopen(fileName,"wb+");
	if (fp == NULL)
	{
		char buf[1024] = {0};
		sprintf(buf,"file open failed. %s",fileName);
		*pException = ICBrother_CreateException(pCBrother,"IOException",buf);
	}
	gdImageJpeg(im,fp,quality);
	fclose(fp);

	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageJpegPtr(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	int quality = 100;
	ICBObject* qualityObj = ICBObjectList_GetCBObject(args,0);
	if (qualityObj != NULL)
	{
		quality = ICBObject_AnyTypeToInt(qualityObj);
	}

	int size = 0;
	char* data = (char*)gdImageJpegPtr(im,&size,quality);
	if (data == NULL || size <= 0)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","jpeg error.");
		return NULL;
	}

	ICBObject* lenObj = ICBrother_CreateCBObjectInt(pCBrother,size + 1);
	ICBObject* byteArrayobj = ICBrother_CreateCBClassObject(pCBrother,"ByteArray",&lenObj,1);
	ICBrother_ReleaseCBObject(pCBrother,lenObj);

	IClassObject* clsobj = ICBObject_ClassObjValue(byteArrayobj);
	ICBByteArray* bytearray = (ICBByteArray*)IClassObject_GetUserParm(clsobj);
	ICBByteArray_WriteBytes(bytearray,data,size);
	free(data);

	return byteArrayobj;
}

ICBObject* CBGdImage_gdImagePng(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* fileNameObj = ICBObjectList_GetCBObject(args,0);
	if (fileNameObj == NULL || ICBObject_Type(fileNameObj) != CB_STRING)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	const char* fileName = ICBObject_StringVal(fileNameObj);
	FILE* fp = fopen(fileName,"wb+");
	if (fp == NULL)
	{
		char buf[1024] = {0};
		sprintf(buf,"file open failed. %s",fileName);
		*pException = ICBrother_CreateException(pCBrother,"IOException",buf);
	}
	gdImagePng(im,fp);
	fclose(fp);

	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImagePngPtr(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	int size = 0;
	char* data = (char*)gdImagePngPtr(im,&size);
	if (data == NULL || size <= 0)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","png error.");
		return NULL;
	}

	ICBObject* lenObj = ICBrother_CreateCBObjectInt(pCBrother,size + 1);
	ICBObject* byteArrayobj = ICBrother_CreateCBClassObject(pCBrother,"ByteArray",&lenObj,1);
	ICBrother_ReleaseCBObject(pCBrother,lenObj);

	IClassObject* clsobj = ICBObject_ClassObjValue(byteArrayobj);
	ICBByteArray* bytearray = (ICBByteArray*)IClassObject_GetUserParm(clsobj);
	ICBByteArray_WriteBytes(bytearray,data,size);
	free(data);

	return byteArrayobj;
}

ICBObject* CBGdImage_gdImageGif(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* fileNameObj = ICBObjectList_GetCBObject(args,0);
	if (fileNameObj == NULL || ICBObject_Type(fileNameObj) != CB_STRING)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	const char* fileName = ICBObject_StringVal(fileNameObj);
	FILE* fp = fopen(fileName,"wb+");
	if (fp == NULL)
	{
		char buf[1024] = {0};
		sprintf(buf,"file open failed. %s",fileName);
		*pException = ICBrother_CreateException(pCBrother,"IOException",buf);
	}
	gdImageGif(im,fp);
	fclose(fp);

	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageGifPtr(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	int size = 0;
	char* data = (char*)gdImageGifPtr(im,&size);
	if (data == NULL || size <= 0)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","gif error.");
		return NULL;
	}

	ICBObject* lenObj = ICBrother_CreateCBObjectInt(pCBrother,size + 1);
	ICBObject* byteArrayobj = ICBrother_CreateCBClassObject(pCBrother,"ByteArray",&lenObj,1);
	ICBrother_ReleaseCBObject(pCBrother,lenObj);

	IClassObject* clsobj = ICBObject_ClassObjValue(byteArrayobj);
	ICBByteArray* bytearray = (ICBByteArray*)IClassObject_GetUserParm(clsobj);
	ICBByteArray_WriteBytes(bytearray,data,size);
	free(data);

	return byteArrayobj;
}

ICBObject* CBGdImage_gdImageBmp(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* fileNameObj = ICBObjectList_GetCBObject(args,0);
	ICBObject* compressionObj = ICBObjectList_GetCBObject(args,1);
	if (fileNameObj == NULL || ICBObject_Type(fileNameObj) != CB_STRING)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	int compression = 0;
	if (compressionObj != NULL)
	{
		compression = ICBObject_AnyTypeToInt(compressionObj);
	}

	const char* fileName = ICBObject_StringVal(fileNameObj);
	FILE* fp = fopen(fileName,"wb+");
	if (fp == NULL)
	{
		char buf[1024] = {0};
		sprintf(buf,"file open failed. %s",fileName);
		*pException = ICBrother_CreateException(pCBrother,"IOException",buf);
	}
	gdImageBmp(im,fp,compression);
	fclose(fp);

	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageBmpPtr(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* compressionObj = ICBObjectList_GetCBObject(args,0);
	int compression = 0;
	if (compressionObj != NULL)
	{
		compression = ICBObject_AnyTypeToInt(compressionObj);
	}

	int size = 0;
	char* data = (char*)gdImageBmpPtr(im,&size,compression);
	if (data == NULL || size <= 0)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","bmp error.");
		return NULL;
	}

	ICBObject* lenObj = ICBrother_CreateCBObjectInt(pCBrother,size + 1);
	ICBObject* byteArrayobj = ICBrother_CreateCBClassObject(pCBrother,"ByteArray",&lenObj,1);
	ICBrother_ReleaseCBObject(pCBrother,lenObj);

	IClassObject* clsobj = ICBObject_ClassObjValue(byteArrayobj);
	ICBByteArray* bytearray = (ICBByteArray*)IClassObject_GetUserParm(clsobj);
	ICBByteArray_WriteBytes(bytearray,data,size);
	free(data);

	return byteArrayobj;
}

ICBObject* CBGdImage_gdImageWebp(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	ICBObject* fileNameObj = ICBObjectList_GetCBObject(args,0);
	if (fileNameObj == NULL || ICBObject_Type(fileNameObj) != CB_STRING)
	{
		return ICBrother_CreateCBObjectBool(pCBrother,false);
	}

	const char* fileName = ICBObject_StringVal(fileNameObj);
	FILE* fp = fopen(fileName,"wb+");
	if (fp == NULL)
	{
		char buf[1024] = {0};
		sprintf(buf,"file open failed. %s",fileName);
		*pException = ICBrother_CreateException(pCBrother,"IOException",buf);
	}
	gdImageWebp(im,fp);
	fclose(fp);

	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageWebpPtr(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	int size = 0;
	char* data = (char*)gdImageWebpPtr(im,&size);
	if (data == NULL || size <= 0)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","webp error.");
		return NULL;
	}

	ICBObject* lenObj = ICBrother_CreateCBObjectInt(pCBrother,size + 1);
	ICBObject* byteArrayobj = ICBrother_CreateCBClassObject(pCBrother,"ByteArray",&lenObj,1);
	ICBrother_ReleaseCBObject(pCBrother,lenObj);

	IClassObject* clsobj = ICBObject_ClassObjValue(byteArrayobj);
	ICBByteArray* bytearray = (ICBByteArray*)IClassObject_GetUserParm(clsobj);
	ICBByteArray_WriteBytes(bytearray,data,size);
	free(data);

	return byteArrayobj;
}

ICBObject* CBGdImage_gdImageCreateFromJpeg(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im != NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is already created.");
		return NULL;
	}

	ICBObject* fileNameObj = ICBObjectList_GetCBObject(args,0);
	if (ICBObject_Type(fileNameObj) == CB_STRING)
	{
		const char* fileName = ICBObject_StringVal(fileNameObj);
		FILE* fp = fopen(fileName,"rb");
		if (fp == NULL)
		{
			char buf[1024] = {0};
			sprintf(buf,"file open failed. %s",fileName);
			*pException = ICBrother_CreateException(pCBrother,"IOException",buf);
			return NULL;
		}
		im = gdImageCreateFromJpeg(fp);
		fclose(fp);
	}
	else if (ICBObject_Type(fileNameObj) == CB_CLASS)
	{
		ICBObject* lenObj = ICBObjectList_GetCBObject(args,1);
		IClassObject* clsObj = ICBObject_ClassObjValue(fileNameObj);
		if (strcmp(IClassObject_GetCBClassName(clsObj),"ByteArray") != 0)
		{
			*pException = ICBrother_CreateException(pCBrother,"GDImageException","image data not is ByteArray.");
			return NULL;
		}

		if (!ICBrother_WriteLockCBClsObject(pCBrother,clsObj))
		{
			ICBrother_CreateException(pCBrother,"SyncException","multi thread access at object func! 'ByteArray' Object!");
			return NULL;
		}

		ICBByteArray* byteArray = (ICBByteArray*)IClassObject_GetUserParm(clsObj);
		const char* data = ICBByteArray_GetBuf(byteArray) + ICBByteArray_GetReadPos(byteArray);
		int len = ICBByteArray_GetWritePos(byteArray) - ICBByteArray_GetReadPos(byteArray);
		if (lenObj != NULL)
		{
			len = ICBObject_AnyTypeToInt(lenObj);
		}
		im = gdImageCreateFromJpegPtr(len,(void*)data);
		ICBrother_WriteUnlockCBClsObject(pCBrother,clsObj);
	}
	else
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image data error.");
		return NULL;
	}

	IClassObject_SetUserParm(obj,im);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageCreateFromPng(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im != NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is already created.");
		return NULL;
	}

	ICBObject* fileNameObj = ICBObjectList_GetCBObject(args,0);
	if (ICBObject_Type(fileNameObj) == CB_STRING)
	{
		const char* fileName = ICBObject_StringVal(fileNameObj);
		FILE* fp = fopen(fileName,"rb");
		if (fp == NULL)
		{
			char buf[1024] = {0};
			sprintf(buf,"file open failed. %s",fileName);
			*pException = ICBrother_CreateException(pCBrother,"IOException",buf);
			return NULL;
		}
		im = gdImageCreateFromPng(fp);
		fclose(fp);
	}
	else if (ICBObject_Type(fileNameObj) == CB_CLASS)
	{
		ICBObject* lenObj = ICBObjectList_GetCBObject(args,1);
		IClassObject* clsObj = ICBObject_ClassObjValue(fileNameObj);
		if (strcmp(IClassObject_GetCBClassName(clsObj),"ByteArray") != 0)
		{
			*pException = ICBrother_CreateException(pCBrother,"GDImageException","image data not is ByteArray.");
			return NULL;
		}

		if (!ICBrother_WriteLockCBClsObject(pCBrother,clsObj))
		{
			ICBrother_CreateException(pCBrother,"SyncException","multi thread access at object func! 'ByteArray' Object!");
			return NULL;
		}

		ICBByteArray* byteArray = (ICBByteArray*)IClassObject_GetUserParm(clsObj);
		const char* data = ICBByteArray_GetBuf(byteArray) + ICBByteArray_GetReadPos(byteArray);
		int len = ICBByteArray_GetWritePos(byteArray) - ICBByteArray_GetReadPos(byteArray);
		if (lenObj != NULL)
		{
			len = ICBObject_AnyTypeToInt(lenObj);
		}
		im = gdImageCreateFromPngPtr(len,(void*)data);
		ICBrother_WriteUnlockCBClsObject(pCBrother,clsObj);
	}
	else
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image data error.");
		return NULL;
	}

	IClassObject_SetUserParm(obj,im);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageCreateFromGif(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im != NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is already created.");
		return NULL;
	}

	ICBObject* fileNameObj = ICBObjectList_GetCBObject(args,0);
	if (ICBObject_Type(fileNameObj) == CB_STRING)
	{
		const char* fileName = ICBObject_StringVal(fileNameObj);
		FILE* fp = fopen(fileName,"rb");
		if (fp == NULL)
		{
			char buf[1024] = {0};
			sprintf(buf,"file open failed. %s",fileName);
			*pException = ICBrother_CreateException(pCBrother,"IOException",buf);
			return NULL;
		}
		im = gdImageCreateFromGif(fp);
		fclose(fp);
	}
	else if (ICBObject_Type(fileNameObj) == CB_CLASS)
	{
		ICBObject* lenObj = ICBObjectList_GetCBObject(args,1);
		IClassObject* clsObj = ICBObject_ClassObjValue(fileNameObj);
		if (strcmp(IClassObject_GetCBClassName(clsObj),"ByteArray") != 0)
		{
			*pException = ICBrother_CreateException(pCBrother,"GDImageException","image data not is ByteArray.");
			return NULL;
		}

		if (!ICBrother_WriteLockCBClsObject(pCBrother,clsObj))
		{
			ICBrother_CreateException(pCBrother,"SyncException","multi thread access at object func! 'ByteArray' Object!");
			return NULL;
		}

		ICBByteArray* byteArray = (ICBByteArray*)IClassObject_GetUserParm(clsObj);
		const char* data = ICBByteArray_GetBuf(byteArray) + ICBByteArray_GetReadPos(byteArray);
		int len = ICBByteArray_GetWritePos(byteArray) - ICBByteArray_GetReadPos(byteArray);
		if (lenObj != NULL)
		{
			len = ICBObject_AnyTypeToInt(lenObj);
		}
		im = gdImageCreateFromGifPtr(len,(void*)data);
		ICBrother_WriteUnlockCBClsObject(pCBrother,clsObj);
	}
	else
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image data error.");
		return NULL;
	}

	IClassObject_SetUserParm(obj,im);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageCreateFromBmp(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im != NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is already created.");
		return NULL;
	}

	ICBObject* fileNameObj = ICBObjectList_GetCBObject(args,0);
	if (ICBObject_Type(fileNameObj) == CB_STRING)
	{
		const char* fileName = ICBObject_StringVal(fileNameObj);
		FILE* fp = fopen(fileName,"rb");
		if (fp == NULL)
		{
			char buf[1024] = {0};
			sprintf(buf,"file open failed. %s",fileName);
			*pException = ICBrother_CreateException(pCBrother,"IOException",buf);
			return NULL;
		}
		im = gdImageCreateFromBmp(fp);
		fclose(fp);
	}
	else if (ICBObject_Type(fileNameObj) == CB_CLASS)
	{
		ICBObject* lenObj = ICBObjectList_GetCBObject(args,1);
		IClassObject* clsObj = ICBObject_ClassObjValue(fileNameObj);
		if (strcmp(IClassObject_GetCBClassName(clsObj),"ByteArray") != 0)
		{
			*pException = ICBrother_CreateException(pCBrother,"GDImageException","image data not is ByteArray.");
			return NULL;
		}

		if (!ICBrother_WriteLockCBClsObject(pCBrother,clsObj))
		{
			ICBrother_CreateException(pCBrother,"SyncException","multi thread access at object func! 'ByteArray' Object!");
			return NULL;
		}

		ICBByteArray* byteArray = (ICBByteArray*)IClassObject_GetUserParm(clsObj);
		const char* data = ICBByteArray_GetBuf(byteArray) + ICBByteArray_GetReadPos(byteArray);
		int len = ICBByteArray_GetWritePos(byteArray) - ICBByteArray_GetReadPos(byteArray);
		if (lenObj != NULL)
		{
			len = ICBObject_AnyTypeToInt(lenObj);
		}
		im = gdImageCreateFromBmpPtr(len,(void*)data);
		ICBrother_WriteUnlockCBClsObject(pCBrother,clsObj);
	}
	else
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image data error.");
		return NULL;
	}

	IClassObject_SetUserParm(obj,im);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageCreateFromWebp(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im != NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is already created.");
		return NULL;
	}

	ICBObject* fileNameObj = ICBObjectList_GetCBObject(args,0);
	if (ICBObject_Type(fileNameObj) == CB_STRING)
	{
		const char* fileName = ICBObject_StringVal(fileNameObj);
		FILE* fp = fopen(fileName,"rb");
		if (fp == NULL)
		{
			char buf[1024] = {0};
			sprintf(buf,"file open failed. %s",fileName);
			*pException = ICBrother_CreateException(pCBrother,"IOException",buf);
			return NULL;
		}
		im = gdImageCreateFromWebp(fp);
		fclose(fp);
	}
	else if (ICBObject_Type(fileNameObj) == CB_CLASS)
	{
		ICBObject* lenObj = ICBObjectList_GetCBObject(args,1);
		IClassObject* clsObj = ICBObject_ClassObjValue(fileNameObj);
		if (strcmp(IClassObject_GetCBClassName(clsObj),"ByteArray") != 0)
		{
			*pException = ICBrother_CreateException(pCBrother,"GDImageException","image data not is ByteArray.");
			return NULL;
		}

		if (!ICBrother_WriteLockCBClsObject(pCBrother,clsObj))
		{
			ICBrother_CreateException(pCBrother,"SyncException","multi thread access at object func! 'ByteArray' Object!");
			return NULL;
		}

		ICBByteArray* byteArray = (ICBByteArray*)IClassObject_GetUserParm(clsObj);
		const char* data = ICBByteArray_GetBuf(byteArray) + ICBByteArray_GetReadPos(byteArray);
		int len = ICBByteArray_GetWritePos(byteArray) - ICBByteArray_GetReadPos(byteArray);
		if (lenObj != NULL)
		{
			len = ICBObject_AnyTypeToInt(lenObj);
		}
		im = gdImageCreateFromWebpPtr(len,(void*)data);
		ICBrother_WriteUnlockCBClsObject(pCBrother,clsObj);
	}
	else
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image data error.");
		return NULL;
	}

	IClassObject_SetUserParm(obj,im);
	return ICBrother_CreateCBObjectBool(pCBrother,true);
}

ICBObject* CBGdImage_gdImageSX(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	return ICBrother_CreateCBObjectInt(pCBrother,gdImageSX(im));
}

ICBObject* CBGdImage_gdImageSY(ICBrother* pCBrother,ICBObjectList* args,IClassObject* obj,ICBException** pException)
{
	gdImagePtr im = (gdImagePtr)IClassObject_GetUserParm(obj);
	if (im == NULL)
	{
		*pException = ICBrother_CreateException(pCBrother,"GDImageException","image is not created.");
		return NULL;
	}

	return ICBrother_CreateCBObjectInt(pCBrother,gdImageSY(im));
}

bool Init(ICBrother* pCBrother)
{
	//regiest your function and class
	ICBrother_RegisterCBModuleClass(pCBrother,"Image",CBGdImage_Init,CBGdImage_Release,"gd");
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","create",CBGdImage_gdImageCreate,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","createTrueColor",CBGdImage_gdImageCreateTrueColor,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","createFromJpeg",CBGdImage_gdImageCreateFromJpeg,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","createFromPng",CBGdImage_gdImageCreateFromPng,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","createFromGif",CBGdImage_gdImageCreateFromGif,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","createFromBmp",CBGdImage_gdImageCreateFromBmp,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","createFromWebp",CBGdImage_gdImageCreateFromWebp,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","colorAllocate",CBGdImage_gdImageColorAllocate,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","colorAllocateAlpha",CBGdImage_gdImageColorAllocateAlpha,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","arc",CBGdImage_gdImageArc,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","filledArc",CBGdImage_gdImageFilledArc,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","ellipse",CBGdImage_gdImageEllipse,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","filledEllipse",CBGdImage_gdImageFilledEllipse,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","rectangle",CBGdImage_gdImageRectangle,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","filledRectangle",CBGdImage_gdImageFilledRectangle,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","fill",CBGdImage_gdImageFill,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","filledToBorder",CBGdImage_gdImageFillToBorder,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","copy",CBGdImage_gdImageCopy,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","copyMerge",CBGdImage_gdImageCopyMerge,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","copyResized",CBGdImage_gdImageCopyResized,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","clone",CBGdImage_gdImageClone,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","scale",CBGdImage_gdImageScale,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","setPixel",CBGdImage_gdImageSetPixel,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","getPixel",CBGdImage_gdImageGetPixel,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","getTrueColorPixel",CBGdImage_gdImageGetTrueColorPixel,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","line",CBGdImage_gdImageLine,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","string",CBGdImage_gdImageString,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","stringUp",CBGdImage_gdImageStringUp,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","stringTTF",CBGdImage_gdImageStringTTF,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","saveJpegFile",CBGdImage_gdImageJpeg,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","saveJpegBytes",CBGdImage_gdImageJpegPtr,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","savePngFile",CBGdImage_gdImagePng,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","savePngBytes",CBGdImage_gdImagePngPtr,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","saveGifFile",CBGdImage_gdImageGif,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","saveGifBytes",CBGdImage_gdImageGifPtr,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","saveBmpFile",CBGdImage_gdImageBmp,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","saveBmpBytes",CBGdImage_gdImageBmpPtr,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","saveWebpFile",CBGdImage_gdImageWebp,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","saveWebpBytes",CBGdImage_gdImageWebpPtr,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","sx",CBGdImage_gdImageSX,true);
	ICBrother_RegisterCBClassFunc(pCBrother,"gd::Image","sy",CBGdImage_gdImageSY,true);

	return true;

}
CREATE_CBROTHER_MODULE(Init)