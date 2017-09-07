//
//  UITextField+EXCategory.m
//  Elex
//
//  Created by 沈丰元 on 2017/9/7.
//  Copyright © 2017年 沈丰元. All rights reserved.
//

#import "UITextField+EXCategory.h"
#import <objc/runtime.h>

static NSString * const PlaceholderColorKeyPath = @"placeholderLabel.textColor";
static NSString *EXLimitTextLengthKey = @"kLimitTextLengthKey";
static NSString *EXEditEndBlockKey = @"kEditEndBlockKey";
@implementation UITextField (EXCategory)
#pragma mark ---placeholderColor
- (void)setPlaceholderColor:(UIColor *)placeholderColor
{
    // 这3行代码的作用：1> 保证创建出placeholderLabel，2> 保留曾经设置过的占位文字
    NSString *placeholder = self.placeholder;
    self.placeholder = @" ";
    self.placeholder = placeholder;
    // 处理xmg_placeholderColor为nil的情况：如果是nil，恢复成默认的占位文字颜色
    if (placeholderColor == nil) {
        placeholderColor = [UIColor colorWithRed:0 green:0 blue:0.0980392 alpha:0.22];
    }
    // 设置占位文字颜色
    [self setValue:placeholderColor forKeyPath:PlaceholderColorKeyPath];
}
/**
 *  获得占位文字颜色
 */
- (UIColor *)placeholderColor
{
    return [self valueForKeyPath:PlaceholderColorKeyPath];
}
#pragma mark ---限制长度
- (void)limitTextLength:(NSInteger)length block:(EditEndBlock)block {
    objc_setAssociatedObject(self, (__bridge const void *)(EXLimitTextLengthKey), [NSNumber numberWithInteger:length],OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
    if (block) {
        objc_setAssociatedObject(self, (__bridge const void *)(EXEditEndBlockKey), block, OBJC_ASSOCIATION_COPY_NONATOMIC);
    }
    
    [self addTarget:self action:@selector(textFieldTextLengthLimit:) forControlEvents:UIControlEventEditingChanged];
    [self addTarget:self action:@selector(textFieldDidEndEdit:) forControlEvents:UIControlEventEditingDidEnd];
}

- (void)textFieldDidEndEdit:(UITextField *)textField {
    EditEndBlock block = objc_getAssociatedObject(self, (__bridge const void *)(EXEditEndBlockKey));
    
    if (block) {
        
        block(textField.text);
    }
}

- (void)textFieldTextLengthLimit:(id)sender
{
    NSNumber *lengthNumber = objc_getAssociatedObject(self, (__bridge const void *)(EXLimitTextLengthKey));
    int length = [lengthNumber intValue];
    //下面是修改部分
    bool isChinese;//判断当前输入法是否是中文
    NSArray *currentar = [UITextInputMode activeInputModes];
    UITextInputMode *current = [currentar firstObject];
    //[[UITextInputMode currentInputMode] primaryLanguage]，废弃的方法
    if ([current.primaryLanguage isEqualToString: @"zh-Hans"]) {
        isChinese = true;
    }
    else
    {
        isChinese = false;
    }
    if(sender == self) {
        // length是自己设置的位数
        NSString *str = [[self text] stringByReplacingOccurrencesOfString:@"?" withString:@""];
        if (isChinese) { //中文输入法下
            UITextRange *selectedRange = [self markedTextRange];
            //获取高亮部分
            UITextPosition *position = [self positionFromPosition:selectedRange.start offset:0];
            // 没有高亮选择的字，则对已输入的文字进行字数统计和限制
            if (!position) {
                if ( str.length>=length) {
                    NSString *strNew = [NSString stringWithString:str];
                    [self setText:[strNew substringToIndex:length]];
                }
            }
            else
            {
                // NSLog(@"输入的");
                
            }
        }else{
            if ([str length]>=length) {
                NSString *strNew = [NSString stringWithString:str];
                [self setText:[strNew substringToIndex:length]];
            }
        }
    }
}

- (void)shake
{
    CAKeyframeAnimation *keyAn = [CAKeyframeAnimation animationWithKeyPath:@"position"];
    [keyAn setDuration:0.5f];
    NSArray *array = [[NSArray alloc] initWithObjects:
                      [NSValue valueWithCGPoint:CGPointMake(self.center.x, self.center.y)],
                      [NSValue valueWithCGPoint:CGPointMake(self.center.x-5, self.center.y)],
                      [NSValue valueWithCGPoint:CGPointMake(self.center.x+5, self.center.y)],
                      [NSValue valueWithCGPoint:CGPointMake(self.center.x, self.center.y)],
                      [NSValue valueWithCGPoint:CGPointMake(self.center.x-5, self.center.y)],
                      [NSValue valueWithCGPoint:CGPointMake(self.center.x+5, self.center.y)],
                      [NSValue valueWithCGPoint:CGPointMake(self.center.x, self.center.y)],
                      [NSValue valueWithCGPoint:CGPointMake(self.center.x-5, self.center.y)],
                      [NSValue valueWithCGPoint:CGPointMake(self.center.x+5, self.center.y)],
                      [NSValue valueWithCGPoint:CGPointMake(self.center.x, self.center.y)],
                      nil];
    [keyAn setValues:array];
    
    NSArray *times = [[NSArray alloc] initWithObjects:
                      [NSNumber numberWithFloat:0.1f],
                      [NSNumber numberWithFloat:0.2f],
                      [NSNumber numberWithFloat:0.3f],
                      [NSNumber numberWithFloat:0.4f],
                      [NSNumber numberWithFloat:0.5f],
                      [NSNumber numberWithFloat:0.6f],
                      [NSNumber numberWithFloat:0.7f],
                      [NSNumber numberWithFloat:0.8f],
                      [NSNumber numberWithFloat:0.9f],
                      [NSNumber numberWithFloat:1.0f],
                      nil];
    [keyAn setKeyTimes:times];
    
    [self.layer addAnimation:keyAn forKey:@"TextAnim"];
}

@end
