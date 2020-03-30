#include "larpandora/LArPandoraInterface/ArtIOMasterAlgorithm.h"

#include "Api/PandoraApi.h"

#include <iostream>

namespace lar_pandora
{

ArtIOMasterAlgorithm::ArtIOMasterAlgorithm()
{
    std::cout << "Custom master is created" << std::endl;
}

pandora::StatusCode ArtIOMasterAlgorithm::InitializeWorkerInstances()
{
    std::cout << "Custom master" << std::endl;
    pandora::StatusCode statusCode = lar_content::MasterAlgorithm::InitializeWorkerInstances();

    return statusCode;
}

} // namespace lar_pandora

