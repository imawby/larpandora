#include "larpandora/LArPandoraInterface/ArtIOMasterAlgorithm.h"

#include "Api/PandoraApi.h"
#include "larpandora/LArPandoraInterface/ArtIOContent.h"

#include <iostream>

using namespace pandora;

namespace lar_pandora
{

ArtIOMasterAlgorithm::ArtIOMasterAlgorithm()
{
    std::cout << "ArtIOMasterAlgorithm::ArtIOMasterAlgorithm" << std::endl;
}

StatusCode ArtIOMasterAlgorithm::Run()
{
    std::cout << "ArtIOMasterAlgorithm::Run" << std::endl;
  
    StatusCode status = MasterAlgorithm::Run();

    std::cout << "ArtIOMasterAlgorithm::Run end" << std::endl;

    return status;
}

StatusCode ArtIOMasterAlgorithm::InitializeWorkerInstances()
{
    std::cout << "ArtIOMasterAlgorithm::InitializeWorkerInstance" << std::endl;
    StatusCode statusCode = lar_content::MasterAlgorithm::InitializeWorkerInstances();
    std::cout << "ArtIOMasterAlgorithm::InitializeWorkerInstance end" << std::endl;

    return statusCode;
}

StatusCode ArtIOMasterAlgorithm::ReadSettings(const TiXmlHandle xmlHandle)
{
    std::cout << "ArtIOMasterAlgorithm::ReadSettings" << std::endl;

    StatusCode status = MasterAlgorithm::ReadSettings(xmlHandle);

    std::cout << "ArtIOMasterAlgorithm::ReadSettings end" << std::endl;
    return status;
}

StatusCode ArtIOMasterAlgorithm::RegisterCustomContent(const Pandora *const pPandora) const
{
    std::cout << "ArtIOMasterAlgorithm::RegisterCustomContent" << std::endl;
    PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, ArtIOContent::RegisterAlgorithms(*pPandora));
    std::cout << "ArtIOMasterAlgorithm::RegisterCustomContent end" << std::endl;
    return STATUS_CODE_SUCCESS;
}

} // namespace lar_pandora

