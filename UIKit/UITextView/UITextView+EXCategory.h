//
//  UITextView+EXCategory.h
//  
//
//  Created by 沈丰元 on 2017/9/7.
//
//

#import <UIKit/UIKit.h>

FOUNDATION_EXPORT double UITextView_PlaceholderVersionNumber;
FOUNDATION_EXPORT const unsigned char UITextView_PlaceholderVersionString[];

@interface UITextView (EXCategory)
/***  背景视图*/
@property (nonatomic, readonly) UILabel *placeholderLabel;
/***  背景字*/
@property (nonatomic, strong) IBInspectable NSString *placeholder;
/***  背景字样式*/
@property (nonatomic, strong) NSAttributedString *attributedPlaceholder;
/***  背景字颜色*/
@property (nonatomic, strong) IBInspectable UIColor *placeholderColor;
/***  限制长度*/
@property (copy, nonatomic) NSNumber *limitLength;
/***  默认背景字颜色*/
+ (UIColor *)defaultPlaceholderColor;
@end
