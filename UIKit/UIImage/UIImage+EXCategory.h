//
//  UIImage+EXCategory.h
//  Elex
//
//  Created by 沈丰元 on 2017/9/7.
//  Copyright © 2017年 沈丰元. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (EXCategory)
/**
 *  颜色转成图片
 *
 *  @param color 颜色
 *
 *  @return 图片
 */
+ (UIImage *)imageWithColor:(UIColor *)color;
/**
 *  图片里的主色调
 *
 *  @param image 图片
 *
 *  @return 颜色
 */
+(UIColor*)mostColor:(UIImage*)image;
/**
 *  获得指定宽度的图片
 *
 *  @param sourceImage 原图
 *  @param defineWidth 宽度
 *
 *  @return 调整后的图片
 */
-(UIImage *) imageCompressForWidth:(UIImage *)sourceImage targetWidth:(CGFloat)defineWidth;
/**
 *  获得指定size的图片
 *
 *  @param image   原始图片
 *  @param newSize 指定的size
 *
 *  @return 调整后的图片
 */
+ (UIImage *)resizeImage:(UIImage *) image withNewSize:(CGSize) newSize;
/**
 *  给直接视图截图
 *
 *  @param view 待截图视图
 *
 *  @return 截图生成的图片
 */
+ (UIImage *)captureWithView:(UIView *)view;

/**
 *  压缩上传图片到指定KB
 *
 *  @param image 压缩的图片
 *  @param kb    压缩后最大KB
 *
 *  @return 压缩后图片的二进制
 */
+ (NSData *)compressOriginalImage:(UIImage *)image toMaxDataSizeKBytes:(CGFloat)kb;

/**
 *  压缩上传图片到指定字节
 *
 *  @param image     压缩的图片
 *  @param maxLength 压缩后最大字节大小
 *  @param maxWidth  压缩后最大宽度
 *
 *  @return  压缩后图片的二进制
 */
+ (NSData *)compressImage:(UIImage *)image toMaxLength:(NSInteger) maxLength maxWidth:(NSInteger)maxWidth;
@end
