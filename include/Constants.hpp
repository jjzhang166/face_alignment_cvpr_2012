/** ****************************************************************************
 *  @file    Constants.hpp
 *  @brief   Identifiers whose associated value cannot be altered
 *  @author  Roberto Valle Fernandez
 *  @date    2015/02
 *  @copyright All rights reserved.
 *  Software developed by UPM PCR Group: http://www.dia.fi.upm.es/~pcr
 ******************************************************************************/

// ----------------------- INCLUDES --------------------------------------------
#include <string>
#include <vector>
#include <boost/serialization/access.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>

// ------------------ RECURSION PROTECTION -------------------------------------
#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

/** ****************************************************************************
 * @brief Parse configuration file constants
 ******************************************************************************/
struct ForestParam
{
  int
  getPatchSize()
  {
    return static_cast<int>(round(face_size*patch_size_ratio));
  };

  int max_depth;   // tree stopping criteria
  int min_patches; // tree stopping criteria
  int ntests;      // number of tests to find the optimal split
  int ntrees;      // number of trees per forest
  int nimages;     // number of images per class
  int npatches;    // number of patches per image
  int face_size;   // face size in pixels
  float patch_size_ratio;    // patch size ratio
  std::string tree_path;     // path to load or save the trees
  std::string image_path;    // path to load images
  std::vector<int> features; // feature channels

  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive &ar, const unsigned int version)
  {
    ar & max_depth;
    ar & min_patches;
    ar & ntests;
    ar & ntrees;
    ar & nimages;
    ar & npatches;
    ar & face_size;
    ar & patch_size_ratio;
    ar & tree_path;
    ar & image_path;
    ar & features;
  }
};

/** ****************************************************************************
 * @brief Class identifiers used by the computer vision algorithms
 ******************************************************************************/
static const float TRAIN_IMAGES_PERCENTAGE = 0.9f;
static const int NUM_HEADPOSE_CLASSES = 5;
static const float NORM_HEADPOSE_VARIANCE_FACTOR = 0.05f;
static const float PATCH_CLOSE_TO_FEATURE = 0.09f;

#endif /* CONSTANTS_HPP */
