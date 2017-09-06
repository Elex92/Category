//
//  UIButton+ImageTitlePosition.h
//  Elex
//
//  Created by 沈丰元 on 2017/9/6.
//  Copyright © 2017年 沈丰元. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, EXButtonEdgeInsetsStyle) {
    EXButtonEdgeInsetsStyleTop, // image在上，label在下
    EXButtonEdgeInsetsStyleLeft, // image在左，label在右
    EXButtonEdgeInsetsStyleBottom, // image在下，label在上
    EXButtonEdgeInsetsStyleRight // image在右，label在左
};

@interface UIButton (ImageTitlePosition)

/**
 *  设置button的titleLabel和imageView的布局样式，及间距
 *
 *  @param style titleLabel和imageView的布局样式
 *  @param space titleLabel和imageView的间距
 */
- (void)layoutButtonWithEdgeInsetsStyle:(EXButtonEdgeInsetsStyle)style
                        imageTitleSpace:(CGFloat)space;

@end
