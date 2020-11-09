#ifndef VULKANPROJECT_SAMPLEAPPLICATION_SRC_APPLICATION_H_
#define VULKANPROJECT_SAMPLEAPPLICATION_SRC_APPLICATION_H_

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
#include <optional>

struct QueueFamilyIndices {
  std::optional<uint32_t> graphicsFamily;
  std::optional<uint32_t> presentFamily;

  bool isComplete() const {
	return graphicsFamily.has_value() && presentFamily.has_value();
  }
};

struct SwapChainSupportDetails {
  VkSurfaceCapabilitiesKHR capabilities;
  std::vector<VkSurfaceFormatKHR> formats;
  std::vector<VkPresentModeKHR> presentModes;
};

class Application {

 public:

  void Run();

 private:

  void InitWindow();

  void InitVulkan();
  void CreateVulkanInstance();
  void CreateSurface();
  void PickPhysicalDevice();
  void CreateLogicalDevice();
  void CreateSwapChain();

  void MainLoop();

  void Cleanup();

  // Helper functions
  std::vector<const char *> GetRequiredExtensions();
  void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& debugCreateInfo);
  bool CheckValidationLayerSupport();
  void SetupDebugMessenger();
  bool IsDeviceSuitable(VkPhysicalDevice device);
  QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);

  GLFWwindow* window = nullptr;

  VkInstance instance = nullptr;
  VkDebugUtilsMessengerEXT debugMessenger = nullptr;
  VkSurfaceKHR surface = nullptr;

  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
  VkDevice logicalDevice = nullptr;

  VkQueue graphicsQueue = nullptr;
  VkQueue presentQueue = nullptr;


  VkSwapchainKHR swapChain = nullptr;
  std::vector<VkImage> swapChainImages;
  VkFormat swapChainImageFormat;
  VkExtent2D swapChainExtent;

  std::vector<VkImageView> swapChainImageViews;

  VkRenderPass renderPass;
  VkPipelineLayout pipelineLayout;

  VkPipeline graphicsPipeline;

  std::vector<VkFramebuffer> swapChainFramebuffers;

  VkCommandPool commandPool;
  std::vector<VkCommandBuffer> commandBuffers;

  VkSemaphore imageAvailableSemaphore;
  VkSemaphore renderFinishedSemaphore;

  std::vector<VkSemaphore> imageAvailableSemaphores;
  std::vector<VkSemaphore> renderFinishedSemaphores;
  std::vector<VkFence> inFlightFences;
  std::vector<VkFence> imagesInFlight;
  size_t currentFrame = 0;

  const uint32_t WIDTH = 800;
  const uint32_t HEIGHT = 600;
  const int MAX_FRAMES_IN_FLIGHT = 2;

  bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
  SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);
  VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &availableFormats);
  VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR> &availablePresentModes);
  VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities);
  void CreateImageViews();
  void CreateGraphicsPipeline();
  VkShaderModule CreateShaderModule(const std::vector<char> &code);
  void CreateRenderPass();
  void CreateFrameBuffers();
  void CreateCommandPool();
  void CreateCommandBuffers();
  void DrawFrame();
  void CreateSemaphores();
};

#endif //VULKANPROJECT_SAMPLEAPPLICATION_SRC_APPLICATION_H_
