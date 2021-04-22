// RUN: mlir-opt %s -linalg-detensorize=aggressive-mode | FileCheck %s -check-prefix=DET-ALL
// RUN: mlir-opt %s -linalg-detensorize | FileCheck %s -check-prefix=DET-CF


#map0 = affine_map<() -> ()>

#attrs = {
  indexing_maps = [#map0, #map0, #map0],
  iterator_types = []
}

func @main(%farg0 : tensor<i32>) -> (tensor<i1>) attributes {} {
  %c10 = constant 10 : i32
  %1 = tensor.from_elements %c10 : tensor<1xi32>
  %reshaped1 = linalg.tensor_reshape %1 [] : tensor<1xi32> into tensor<i32>
  %3 = linalg.init_tensor [] : tensor<i1>
  %4 = linalg.generic #attrs
    ins(%farg0, %reshaped1 : tensor<i32>, tensor<i32>)
    outs(%3 : tensor<i1>) {
    ^bb0(%arg0: i32, %arg1: i32, %arg2: i1):
      %8 = cmpi slt, %arg0, %arg1 : i32
      linalg.yield %8 : i1
  } -> tensor<i1>
  return %4 : tensor<i1>
}


// DET-ALL-LABEL: func @main(%{{.*}}: tensor<i32>)
// DET-ALL-NEXT:    constant 10
// DET-ALL-NEXT:    tensor.extract %{{.*}}[]
// DET-ALL-NEXT:    cmpi slt, %{{.*}}, %{{.*}}
// DET-ALL-NEXT:    tensor.from_elements %{{.*}}
// DET-ALL-NEXT:    linalg.tensor_reshape %{{.*}}
// DET-ALL-NEXT:    return %{{.*}} : tensor<i1>
// DET-ALL-NEXT:  }

// DET-CF-LABEL: func @main(%{{.*}}: tensor<i32>)
// DET-CF-NEXT:    constant 10 : i32
// DET-CF-NEXT:    tensor.from_elements %{{.*}}
// DET-CF-NEXT:    linalg.tensor_reshape %{{.*}}
// DET-CF-NEXT:    linalg.init_tensor [] : tensor<i1>
// DET-CF-NEXT:    linalg.generic
// DET-CF-NEXT:    ^{{.*}}(%{{.*}}: i32, %{{.*}}: i32, %{{.*}}: i1)
// DET-CF-NEXT:      cmpi slt, %{{.*}}, %{{.*}}
// DET-CF-NEXT:      linalg.yield %{{.*}}
// DET-CF-NEXT:    } -> tensor<i1>
// DET-CF-NEXT:    return %{{.*}}
// DET-CF-NEXT:  }