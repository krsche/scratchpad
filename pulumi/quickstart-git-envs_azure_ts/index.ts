import * as pulumi from "@pulumi/pulumi";
import * as resources from "@pulumi/azure-native/resources";
import * as storage from "@pulumi/azure-native/storage";


// VARIABLES
const stackname = pulumi.getStack();


// RESOURCES
const rg = new resources.ResourceGroup("rg-quickstart-" + stackname + "-weu-");

const sa = new storage.StorageAccount("krschesp" + stackname + "saquickweu", {
    resourceGroupName: rg.name,
    sku: {
        name: storage.SkuName.Standard_LRS,
    },
    kind: storage.Kind.StorageV2
});

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


// EXPORTS
export const websiteEndpoint = sa.primaryEndpoints.web;