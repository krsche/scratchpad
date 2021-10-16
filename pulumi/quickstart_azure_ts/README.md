# Quickstart - Azure - Typescript
This project was created following the [Get Started Guide on pulumis website](https://www.pulumi.com/docs/get-started/azure/).  
Afterwards the stack was deleted.  

To create and configure a new stack, run the following:  
```bash
# Create a new stack (select new, enter name)
pulumi stack

# Set subscription and tenant
pulumi config set azure-native:subscriptionID <SUBSCRIPTION-ID>
pulumi config set azure-native:tenantId <TENANT-ID>
pulumi config set azure-native:location <LOCATION>
```