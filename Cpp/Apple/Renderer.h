#import <MetalKit/MetalKit.h>

@interface Renderer : NSObject <MTKViewDelegate>

#if TARGET_OS_IPHONE
-(nonnull instancetype)initWithMetalKitView:(nonnull MTKView *)view;
#else
-(nonnull instancetype)initWithMetalKitView:(nonnull MTKView *)view withLabel:(nonnull NSTextField*) label;
#endif

@end
