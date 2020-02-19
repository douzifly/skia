/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrTiledGradientEffect.fp; do not modify.
 **************************************************************************************************/
#ifndef GrTiledGradientEffect_DEFINED
#define GrTiledGradientEffect_DEFINED
#include "include/core/SkTypes.h"
#include "include/private/SkM44.h"

#include "src/gpu/GrCoordTransform.h"
#include "src/gpu/GrFragmentProcessor.h"
class GrTiledGradientEffect : public GrFragmentProcessor {
public:
    static std::unique_ptr<GrFragmentProcessor> Make(
            std::unique_ptr<GrFragmentProcessor> colorizer,
            std::unique_ptr<GrFragmentProcessor> gradLayout, bool mirror, bool makePremul,
            bool colorsAreOpaque) {
        return std::unique_ptr<GrFragmentProcessor>(new GrTiledGradientEffect(
                std::move(colorizer), std::move(gradLayout), mirror, makePremul, colorsAreOpaque));
    }
    GrTiledGradientEffect(const GrTiledGradientEffect& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "TiledGradientEffect"; }
    int colorizer_index = -1;
    int gradLayout_index = -1;
    bool mirror;
    bool makePremul;
    bool colorsAreOpaque;

private:
    GrTiledGradientEffect(std::unique_ptr<GrFragmentProcessor> colorizer,
                          std::unique_ptr<GrFragmentProcessor> gradLayout, bool mirror,
                          bool makePremul, bool colorsAreOpaque)
            : INHERITED(kGrTiledGradientEffect_ClassID,
                        (OptimizationFlags)kCompatibleWithCoverageAsAlpha_OptimizationFlag |
                                (colorsAreOpaque && gradLayout->preservesOpaqueInput()
                                         ? kPreservesOpaqueInput_OptimizationFlag
                                         : kNone_OptimizationFlags))
            , mirror(mirror)
            , makePremul(makePremul)
            , colorsAreOpaque(colorsAreOpaque) {
        SkASSERT(colorizer);
        colorizer_index = this->numChildProcessors();
        this->registerChildProcessor(std::move(colorizer));
        SkASSERT(gradLayout);
        gradLayout_index = this->numChildProcessors();
        this->registerChildProcessor(std::move(gradLayout));
    }
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    typedef GrFragmentProcessor INHERITED;
};
#endif