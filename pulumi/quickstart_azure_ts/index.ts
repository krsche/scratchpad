import * as pulumi from "@pulumi/pulumi";
import * as resources from "@pulumi/azure-native/resources";
import * as storage from "@pulumi/azure-native/storage";

// Create an Azure Resource Group
const rg = new resources.ResourceGroup("pulumiResourceGroup");

// Create an Azure resource (Storage Account)
const sa = new storage.StorageAccount("krschepulumisa", {
    resourceGroupName: rg.name,
    sku: {
        name: storage.SkuName.Standard_LRS,
    },
    kind: storage.Kind.StorageV2
});

// Export the primary key of the Storage Account
const storageAccountKeys = pulumi.all([rg.name, sa.name]).apply(([resourceGroupName, accountName]) =>
storage.listStorageAccountKeys({ resourceGroupName, accountName }));
export const primaryStorageKey = storageAccountKeys.keys[0].value;

// Enable Website and supply index.html
const saWebsite = new storage.StorageAccountStaticWebsite("sawebsite", {
    accountName: sa.name,
    resourceGroupName: rg.name,
    indexDocument: "index.html"
})

const blobWebsite = new storage.Blob("index.html", {
    resourceGroupName: rg.name,
    accountName: sa.name,
    containerName: saWebsite.containerName,
    source: new pulumi.asset.FileAsset("index.html"),
    contentType: "text/html"
})

export const websiteEndpoint = sa.primaryEndpoints.web;