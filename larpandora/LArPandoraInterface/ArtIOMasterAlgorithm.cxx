#include "larpandora/LArPandoraInterface/ArtIOMasterAlgorithm.h"

#include "Api/PandoraApi.h"

#include <iostream>

namespace lar_pandora
{

ArtIOMasterAlgorithm::ArtIOMasterAlgorithm()
{
}

pandora::StatusCode ArtIOAlgorithm::InitializeWorkerInstances()
{
    std::cout << "Custom master" << std::endl;
    pandora::StatusCode statusCode = MasterAlgorithm::InitializeWorkerInstances();

    return statusCode;
}

} // namespace lar_pandora

