/**
 *  @file   larpandora/ArtIOContent.cxx
 *
 *  @brief  Algorithm regsitration for Art IO content
 * 
 *  $Log: $
 */

#include "larpandora/LArPandoraInterface/ArtIOContent.h"

#include "Pandora/Pandora.h"
#include "Api/PandoraApi.h"

#include "larpandora/LArPandoraInterface/TestIOAlgorithm.h"
#include "larpandora/LArPandoraInterface/ArtIOMasterAlgorithm.h"

using namespace pandora;

StatusCode ArtIOContent::RegisterAlgorithms(const Pandora &pandora)
{
    std::cout << "ArtIOContent::RegisterAlgorithm" << std::endl;
    PANDORA_THROW_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterAlgorithmFactory(
                pandora, "ArtIOMaster", new lar_pandora::ArtIOMasterAlgorithm::Factory));

    PANDORA_THROW_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterAlgorithmFactory(
                pandora, "TestIO", new lar_pandora::TestIOAlgorithm::Factory));
    std::cout << "ArtIOContent::RegisterAlgorithm complete" << std::endl;

    return STATUS_CODE_SUCCESS;
}

