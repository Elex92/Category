//
//  UIButton+EXBlock.m
//  Elex
//
//  Created by 沈丰元 on 2017/9/6.
//  Copyright © 2017年 沈丰元. All rights reserved.
//

#import "UIButton+EXBlock.h"
#import <objc/runtime.h>
static const void *EX_UIButtonBlockKey = &EX_UIButtonBlockKey;
@implementation UIButton (EXBlock)

-(void)addActionHandler:(EXTouchedButtonBlock)touchHandler{
    objc_setAssociatedObject(self, EX_UIButtonBlockKey, touchHandler, OBJC_ASSOCIATION_COPY_NONATOMIC);
    [self addTarget:self action:@selector(blockActionTouched:) forControlEvents:UIControlEventTouchUpInside];
}
-(void)blockActionTouched:(UIButton *)btn{
    EXTouchedButtonBlock block = objc_getAssociatedObject(self, EX_UIButtonBlockKey);
    if (block) {
        block(btn.tag);
    }
}

@end
