//
//  NSObject+RACAppKitBindings.h
//  ReactiveCocoa
//
//  Created by Josh Abernathy on 4/17/12.
//  Copyright (c) 2012 GitHub, Inc. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class RACBindingEndpoint;

@interface NSObject (RACAppKitBindings)

// Invokes -rac_bind:options: without any options.
- (RACBindingEndpoint *)rac_bind:(NSString *)binding;

// Applies a Cocoa binding to the receiver, then exposes a RACBinding-based
// interface for manipulating it.
//
// Creating two of the same bindings on the same object will result in undefined
// behavior.
//
// binding - The name of the binding. This must not be nil.
// options - Any options to pass to Cocoa Bindings. This may be nil.
//
// Returns a RACBindingEndpoint which will send future values from the receiver,
// and update the receiver when values are sent to the endpoint.
- (RACBindingEndpoint *)rac_bind:(NSString *)binding options:(NSDictionary *)options;

@end

@interface NSObject (RACAppKitBindingsDeprecated)

- (void)rac_bind:(NSString *)binding toObject:(id)object withKeyPath:(NSString *)keyPath __attribute__((deprecated("Use -rac_bind:options: instead")));
- (void)rac_bind:(NSString *)binding toObject:(id)object withKeyPath:(NSString *)keyPath nilValue:(id)nilValue __attribute__((deprecated("Use -rac_bind:options: instead")));
- (void)rac_bind:(NSString *)binding toObject:(id)object withKeyPath:(NSString *)keyPath transform:(id (^)(id value))transformBlock __attribute__((deprecated("Use -rac_bind:options: instead")));
- (void)rac_bind:(NSString *)binding toObject:(id)object withNegatedKeyPath:(NSString *)keyPath __attribute__((deprecated("Use -rac_bind:options: instead")));

@end
